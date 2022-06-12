// Copyright 2022 Narlyeev Parahat

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

#include "include/Kruskal_MST.h"
#include "include/mst_finder.h"

MSTFinder::MSTFinder(): message_("") {}

void MSTFinder::help(const char * appname,
  const char * message) {
  message_ =
    std::string(message) +
    "This is minimum spanning tree finding application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <number_of_nodes> <number_of_edges> " +
    "<edge_1> <edge_2> <edge_3> <etc..>\n\n" +

    "Where all edges should be provided in the next format:\n" +
    "<source_node,destination_node,weight>.\n";
}

bool MSTFinder::validateNumberOfArguments(int argc,
  const char ** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 4) {
    help(argv[0], "ERROR: Should be at least 3 arguments.\n\n");
    return false;
  }
  return true;
}

Edge parseEdge(const char * arg) {
  if (arg[5] != '\0')
    throw std::string("Wrong edge format!");
  Edge edge;
  try {
    edge.src = std::stoi(arg + 0);
    edge.dst = std::stoi(arg + 2);
    edge.weight = std::stoi(arg + 4);
  } catch (std::invalid_argument & e) {
    throw std::string("Wrong edge format!");
  }
  return edge;
}

int parseInt(const char * arg) {
  int value;
  try {
    value = std::stoi(arg);
  } catch (std::invalid_argument & e) {
    throw std::string("Wrong edges or nodes number format!");
  }
  return value;
}

void CheckCount(int argc, int length) {
  if (argc - 3 != length)
    throw std::string("Wrong number of edges provided!");
}

std::string MSTFinder::operator()(int argc,
  const char ** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  int E, V;
  try {
    V = parseInt(argv[1]);
    E = parseInt(argv[2]);
    CheckCount(argc, E);
  } catch (std::string & str) {
    return str;
  }
  Graph graph(E, V);
  try {
    for (int i = 3; i < argc; i++) {
      Edge temp = parseEdge(argv[i]);
      graph.insertEdge(temp);
    }
  } catch (std::string & str) {
    return str;
  }
  std::ostringstream stream;
  std::vector < Edge > result = graph.KruskalMST();
  stream << "MST: ";
  for (size_t i = 0; i < result.size(); i++) {
    stream << result[i].src << "->" << result[i].dst << " ";
  }
  message_ = stream.str();
  return message_;
}


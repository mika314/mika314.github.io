#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <unordered_map>

int main()
{
  std::ifstream f("bucket-list.md");
  std::string line;
  std::multimap<float, std::string> items;
  while (std::getline(f, line))
  {
    if (line.find("1. [ ] ") != 0)
      continue;
    static const std::unordered_map<std::string, int> priority = {
      {"p1", 1}, {"p2", 2}, {"p3", 4}, {"p4", 8}};
    static const std::unordered_map<std::string, int> complexity = {
      {"XS", 1}, {"S", 2}, {"M", 4}, {"L", 8}, {"XL", 16}};
    std::istringstream strm(line.substr(7));
    std::string p, c;
    strm >> p >> c;
    const auto pIter = priority.find(p);
    if (pIter == std::end(priority))
    {
      std::cerr << "unknown priority: '" << p << "' in line " << line << std::endl;
      continue;
    }
    const auto cIter = complexity.find(c);
    if (cIter == std::end(complexity))
    {
      std::cerr << "unknown complexity: '" << c << "' in line " << line << std::endl;
      continue;
    }
    items.insert(std::make_pair(pIter->second + 1 * cIter->second, line));
  }
  std::ofstream of("bucket-list-prioritized.md");
  of << R"(---
layout: page
title: Prioritized Bucket List
permalink: /bucket-list-prioritized/
---

# My Prioritized Bucket List

)";

  for (const auto &item : items)
    of << item.second << std::endl;
}

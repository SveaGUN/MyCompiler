#ifndef UTILITY_H
#define UTILITY_H

#include <string>

bool CompareIgnoreCase(std::string lhs, std::string rhs);
bool CompareCharIgnoreCase(char lhs, char rhs);
void LogError(std::string msg);
#endif
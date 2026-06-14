#include "Akane.h"

using namespace std;

/// <summary>
/// 大文字小文字を無視して文字列を比較する
/// </summary>
/// <param name="lhs">左辺</param>
/// <param name="rhs">右辺/param>
/// <returns>lhsとrhsが等しいならtrue</returns>
bool CompareIgnoreCase(string lhs, string rhs)
{
    if (lhs.length() != rhs.length()) { return false; }

    return equal(lhs.begin(), lhs.end(), rhs.begin(), CompareCharIgnoreCase);
}

/// <summary>
/// 大文字小文字を無視して文字を比較する
/// </summary>
/// <param name="lhs">左辺</param>
/// <param name="rhs">右辺</param>
/// <returns>lhsとrhsが等しいならtrue</returns>
bool CompareCharIgnoreCase(char lhs, char rhs)
{
    return (tolower(lhs) == tolower(rhs));
}

void LogError(std::string msg) {
    cout << "エラー : " << msg << '\n';
}
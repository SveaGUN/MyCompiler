#include <iostream>
#include <fstream>
#include "Akane.h"

using namespace std;

char lineBuffer[MAX_LINE_LEN];
std::ifstream fIn;
int currentLineNum;
int lineIndex = 0;//一行n番目

/// <summary>
/// 指定した名前のソースファイルを開く
/// </summary>
/// <param name="fileName">ソースファイル名</param>
/// <returns>0,-1</returns>
int OpenSourceFile(string& fileName) {
    fIn.open(fileName.c_str());

    if (!fIn) {
        cout << "ファイル " << fileName << " は開けませんわ！\n";
        return -1;
    }
    currentLineNum = 0;

    return 0;
}

/// <summary>
/// 次の一文字を返す
/// </summary>
/// <returns></returns>
static int NextChar() {
    int ch = 0;

    if (lineIndex == -1) {
        //一行読み込む
        fIn.getline(lineBuffer, MAX_LINE_LEN);
        if (fIn) {
            ++currentLineNum;//行番号をインクリメント
            lineIndex = 0;
            RemoveComment(lineBuffer);
        }
        else if (fIn.eof()) { return EOF; }
        else {
            LogError("ファイル読み込みエラーですわ！");
        }
    }

    ch = (int)lineBuffer[lineIndex++];
    if (ch == 0) { lineIndex = -1; } //ch == null

    return ch;
}

/// <summary>
/// コメントを削除する
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
static char* RemoveComment(char* s) {
    int len = strlen(s);
    char ws[MAX_LINE_LEN];
    char ch = 0;
    int j = 0;
    for (int i = 0; i < len; ++i) {
        ch = s[i];

        // /が二回続くならそれ以降は破棄する
        if ((ch == '/') && (i < len - 1)) {
            if (s[i + 1] == '/') {
                break;
            }
        }

        ws[j++] = ch;
    }

    ws[j] = 0;//null終端文字
    strcpy(s, ws);

    return s;
}
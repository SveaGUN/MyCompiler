#include <iostream>
#include <string>

#include "Akane.h" 
#include "util.h"

using namespace std;

//グローバル変数
std::string SrcFileName = "";

bool usePRINT_LINE = false;
bool useGEN_LIST = false;
bool useEXECUTE = false;
bool useDISP_CODE = false;
bool useVERBOSE = false;

//プロトタイプ宣言
int ProcessCmdLine(int argc, char* argv[]);


int main(int argc, char* argv[]) {
    //コマンドラインの処理
    ProcessCmdLine(argc, argv);

    //ソースを開く

    //コンパイル

    //ソースを閉じる

    //実行オプション コンパイル成功時に実行

    return 0;
}

/// <summary>
/// コマンドラインの処理を行う
/// </summary>
/// <param name="argc">引数の数</param>
/// <param name="argv">引数</param>
/// <returns></returns>
int ProcessCmdLine(int argc, char* argv[]) {
    using namespace Opt;
    
    for (int i = 1; i < argc; ++i) {
        string arg = string(argv[i]);

        //最初の文字がハイフンならオプションと見なす
        if (arg[0] == '-') {
            if (CompareIgnoreCase(arg, PRINT_LINE) || CompareIgnoreCase(arg, PRINT_LINE_S)) {
                usePRINT_LINE = true;
                cout << PRINT_LINE << '\n';
            }
            else if (CompareIgnoreCase(arg, GEN_LIST) || CompareIgnoreCase(arg, GEN_LIST_S)) {
                useGEN_LIST = true;
                cout << GEN_LIST << '\n';
            }
            else if (CompareIgnoreCase(arg, EXECUTE) || CompareIgnoreCase(arg, EXECUTE_S)) {
                useEXECUTE = true;
                cout << EXECUTE << '\n';
            }
            else if (CompareIgnoreCase(arg, DISP_CODE) || CompareIgnoreCase(arg, DISP_CODE_S)) {
                useDISP_CODE = true;
                cout << DISP_CODE << '\n';
            }
            else if (CompareIgnoreCase(arg, VERBOSE) || CompareIgnoreCase(arg, VERBOSE_S)) {
                useVERBOSE = true;
                cout << VERBOSE << '\n';
            }
            else {
                cout << "無効なオプションですわ～～～！\n";
                return -1;
            }
        }
        //オプションでない場合はコンパイルするソースファイル名
        else {
            SrcFileName = arg;
        }
    }

    return 0;
}
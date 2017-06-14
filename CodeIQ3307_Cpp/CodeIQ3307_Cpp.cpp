// CodeIQ3307_Cpp.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

int calc(string input);

int main()
{
	// 標準入力よりインプット取得
	string inputStr;
	getline(cin, inputStr);
	//inputStr = "SDIL"; // 20
	//inputStr = "CM"; // 16
	//inputStr = "CSILDC"; // 24

	//int input = std::strtol(inputStr.c_str(), 0, 10);

	// すべてのパターンの数を計算する
	int result = calc(inputStr);

	// 結果
	std::stringstream stringstream;
	stringstream << result;

	// 標準出力へ結果出力
	cout << stringstream.str() << endl;
	return 0;
}

int calc(string input) {
	int align = 0;

	for (unsigned int i = 0; i < input.size(); i++) {
		int charSize = 0;

		char c = input.at(i);
		switch (c) {
		case 'C':
			// なし
			charSize = 1;
			break;
		case 'S':
			// 偶数アドレス
			if (align % 2 != 0) {
				align += 2 - (align % 2);
			}
			charSize = 2;
			break;
		case 'I':
			// 4の倍数アドレス
			if (align % 4 != 0) {
				align += 4 - (align % 4);
			}
			charSize = 4;
			break;
		case 'L':
			// 4の倍数アドレス
			if (align % 4 != 0) {
				align += 4 - (align % 4);
			}
			charSize = 8;
			break;
		case 'D':
			// 8の倍数アドレス
			if (align % 8 != 0) {
				align += 8 - (align % 8);
			}
			charSize = 8;
			break;
		case 'M':
			// 16の倍数アドレス
			if (align % 16 != 0) {
				align += 16 - (align % 16);
			}
			charSize = 16;
			break;
		default:
			break;
		}

		if (i != input.size() - 1) {
			align += charSize;
		}
	}

	return align;
}
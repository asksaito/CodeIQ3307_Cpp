// CodeIQ3307_Cpp.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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
	// �W�����͂��C���v�b�g�擾
	string inputStr;
	getline(cin, inputStr);
	//inputStr = "SDIL"; // 20
	//inputStr = "CM"; // 16
	//inputStr = "CSILDC"; // 24

	//int input = std::strtol(inputStr.c_str(), 0, 10);

	// ���ׂẴp�^�[���̐����v�Z����
	int result = calc(inputStr);

	// ����
	std::stringstream stringstream;
	stringstream << result;

	// �W���o�͂֌��ʏo��
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
			// �Ȃ�
			charSize = 1;
			break;
		case 'S':
			// �����A�h���X
			if (align % 2 != 0) {
				align += 2 - (align % 2);
			}
			charSize = 2;
			break;
		case 'I':
			// 4�̔{���A�h���X
			if (align % 4 != 0) {
				align += 4 - (align % 4);
			}
			charSize = 4;
			break;
		case 'L':
			// 4�̔{���A�h���X
			if (align % 4 != 0) {
				align += 4 - (align % 4);
			}
			charSize = 8;
			break;
		case 'D':
			// 8�̔{���A�h���X
			if (align % 8 != 0) {
				align += 8 - (align % 8);
			}
			charSize = 8;
			break;
		case 'M':
			// 16�̔{���A�h���X
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
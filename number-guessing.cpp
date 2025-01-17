#include <stdio.h>
#include <stdlib.h>		// rand()を使うため
#include <time.h>		// time()乱数の種用
#include <ctype.h>		// isdigit()を使うため
#include <string.h>		// strcspn()を使うため


// プレイヤーの入力が数字かどうかを確認する関数
int isValidInteger(char* str) {
	if (str[0] == '-' || str[0] == '+') {  // 負の数やプラス記号も許可
		str++;
	}
	while (*str) {
		if (!isdigit(*str)) {  // 数字以外の文字があれば無効
			return 0;
		}
		str++;
	}
	return 1;  // 全て数字なら有効
}

int main(void) {

	int keepPlaying = 1; // ゲーム繰り返し続行するかのフラグ

	while(keepPlaying == 1){

		int count = 1;		// 何回で正解したかを数えるための変数
		char input[256];	// プレイヤーの入力用。数字意外が入力されることを考慮して文字列にした。
		int r = 0;			// 乱数。
		int r_max = 99;		// デフォルトの乱数最大値
		int mode;			// モード
		int answer;			// プレイヤーの回答

		// 導入部分
		printf("こんにちは。数当てゲームです。\n");
		printf("モードを選んでください。(0:かんたん, 1:ふつう)\n");
		printf("※ かんたんモードでは、答えの±5以内の数字を入力すると「惜しいです！」と表示されます。\n");

		// 序盤で乱数の種を設定
		srand((unsigned int)time(NULL));

		// プレイヤー入力。値が不正でないか調べ、モードを決定＆表示する。
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		while (1) {
			if (input[0] == '\0')
			{
				printf("何か入力してください。\n");
				fgets(input, sizeof(input), stdin);
				input[strcspn(input, "\n")] = '\0';
			}
			else if (!(isValidInteger(input)))
			{
				printf("\nモード選択では(0:かんたん, 1:ふつう)のどちらかを半角数字で入力してください。\n");
				fgets(input, sizeof(input), stdin);
				input[strcspn(input, "\n")] = '\0';
			}
			else
			{
				break;
			}
		}

		mode = atoi(input);
		if (mode == 0) {
			printf("\nそれでは、かんたんモードで開始します。れっつご～！\n\n");
		}
		else if (mode == 1) {
			printf("\nそれでは、ふつうモードで開始します。れっつご～！\n\n");
		}
		else {
			printf("\nこちらの提示を無視した好奇心旺盛なあなたには鬼畜モードをご提供させていただきます。\n");
			printf("LET DIE!!!!\n\n");
		}


		// 乱数決定
		if (!(mode == 1 || mode == 0))
		{
			r_max = RAND_MAX;
		}
		r = 1 + rand() % r_max;

		printf("私が思い浮かべた数字を当ててください。\n");
		printf("その数は1～%dのいずれかの整数です。\n", r_max);


		while (1) {
			// プレイヤーが回答を入力
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = '\0';
			while (1) {
				if (isValidInteger(input) == 1) {
					break;
				}
				else
				{
					printf("1～%dの整数を半角数字で入力してください。\n", r_max);
					fgets(input, sizeof(input), stdin);
					input[strcspn(input, "\n")] = '\0';
				}
			}
			answer = atoi(input);

			// 回答を正当と比較
			// かんたんモードではanswerがrの+-5以内だった場合に「惜しいです！」と教えてくれる
			if (answer < r)
			{
				if ((mode == 0) && ((answer <= r + 5) && (answer >= r - 5)))
				{
					printf("\n惜しいです！それより少しだけ大きい数字です。\n");
				}
				else {
					printf("\nそれより大きい数字です。\n");
				}
			}
			else if (answer > r)
			{
				if ((mode == 0) && ((answer <= r + 5) && (answer >= r - 5))) {
					printf("\n惜しいです！それより少しだけ小さい数字です。\n");
				}
				else
				{
					printf("\nそれより小さい数字です\n");
				}
			}
			else {
				printf("正解です！\n\n");
				break;
			}
			count++;
		}
		printf("あなたは%d回で正解しました。\n", count);
		printf("もう一度プレイしますか？(1:続行, 0:終了)\n");

		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "1") == 0) {
			printf("\n\n続行します。\n\n");
		}
		else {
			keepPlaying = 0;
		}
	}
	printf("終了します。\n");
	getchar();

}
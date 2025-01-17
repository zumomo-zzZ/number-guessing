#include <stdio.h>
#include <stdlib.h>		// rand()���g������
#include <time.h>		// time()�����̎�p
#include <ctype.h>		// isdigit()���g������
#include <string.h>		// strcspn()���g������


// �v���C���[�̓��͂��������ǂ������m�F����֐�
int isValidInteger(char* str) {
	if (str[0] == '-' || str[0] == '+') {  // ���̐���v���X�L��������
		str++;
	}
	while (*str) {
		if (!isdigit(*str)) {  // �����ȊO�̕���������Ζ���
			return 0;
		}
		str++;
	}
	return 1;  // �S�Đ����Ȃ�L��
}

int main(void) {

	int keepPlaying = 1; // �Q�[���J��Ԃ����s���邩�̃t���O

	while(keepPlaying == 1){

		int count = 1;		// ����Ő����������𐔂��邽�߂̕ϐ�
		char input[256];	// �v���C���[�̓��͗p�B�����ӊO�����͂���邱�Ƃ��l�����ĕ�����ɂ����B
		int r = 0;			// �����B
		int r_max = 99;		// �f�t�H���g�̗����ő�l
		int mode;			// ���[�h
		int answer;			// �v���C���[�̉�

		// ��������
		printf("����ɂ��́B�����ăQ�[���ł��B\n");
		printf("���[�h��I��ł��������B(0:���񂽂�, 1:�ӂ�)\n");
		printf("�� ���񂽂񃂁[�h�ł́A�����́}5�ȓ��̐�������͂���Ɓu�ɂ����ł��I�v�ƕ\������܂��B\n");

		// ���Ղŗ����̎��ݒ�
		srand((unsigned int)time(NULL));

		// �v���C���[���́B�l���s���łȂ������ׁA���[�h�����聕�\������B
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		while (1) {
			if (input[0] == '\0')
			{
				printf("�������͂��Ă��������B\n");
				fgets(input, sizeof(input), stdin);
				input[strcspn(input, "\n")] = '\0';
			}
			else if (!(isValidInteger(input)))
			{
				printf("\n���[�h�I���ł�(0:���񂽂�, 1:�ӂ�)�̂ǂ��炩�𔼊p�����œ��͂��Ă��������B\n");
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
			printf("\n����ł́A���񂽂񃂁[�h�ŊJ�n���܂��B������`�I\n\n");
		}
		else if (mode == 1) {
			printf("\n����ł́A�ӂ����[�h�ŊJ�n���܂��B������`�I\n\n");
		}
		else {
			printf("\n������̒񎦂𖳎������D��S�����Ȃ��Ȃ��ɂ͋S�{���[�h�����񋟂����Ă��������܂��B\n");
			printf("LET DIE!!!!\n\n");
		}


		// ��������
		if (!(mode == 1 || mode == 0))
		{
			r_max = RAND_MAX;
		}
		r = 1 + rand() % r_max;

		printf("�����v�������ׂ������𓖂ĂĂ��������B\n");
		printf("���̐���1�`%d�̂����ꂩ�̐����ł��B\n", r_max);


		while (1) {
			// �v���C���[���񓚂����
			fgets(input, sizeof(input), stdin);
			input[strcspn(input, "\n")] = '\0';
			while (1) {
				if (isValidInteger(input) == 1) {
					break;
				}
				else
				{
					printf("1�`%d�̐����𔼊p�����œ��͂��Ă��������B\n", r_max);
					fgets(input, sizeof(input), stdin);
					input[strcspn(input, "\n")] = '\0';
				}
			}
			answer = atoi(input);

			// �񓚂𐳓��Ɣ�r
			// ���񂽂񃂁[�h�ł�answer��r��+-5�ȓ��������ꍇ�Ɂu�ɂ����ł��I�v�Ƌ����Ă����
			if (answer < r)
			{
				if ((mode == 0) && ((answer <= r + 5) && (answer >= r - 5)))
				{
					printf("\n�ɂ����ł��I�����菭�������傫�������ł��B\n");
				}
				else {
					printf("\n������傫�������ł��B\n");
				}
			}
			else if (answer > r)
			{
				if ((mode == 0) && ((answer <= r + 5) && (answer >= r - 5))) {
					printf("\n�ɂ����ł��I�����菭�����������������ł��B\n");
				}
				else
				{
					printf("\n�����菬���������ł�\n");
				}
			}
			else {
				printf("�����ł��I\n\n");
				break;
			}
			count++;
		}
		printf("���Ȃ���%d��Ő������܂����B\n", count);
		printf("������x�v���C���܂����H(1:���s, 0:�I��)\n");

		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';

		if (strcmp(input, "1") == 0) {
			printf("\n\n���s���܂��B\n\n");
		}
		else {
			keepPlaying = 0;
		}
	}
	printf("�I�����܂��B\n");
	getchar();

}
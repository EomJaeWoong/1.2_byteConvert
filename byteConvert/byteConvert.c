#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	unsigned int shData = 0;
	unsigned int shTemp = 0;

	int iInputByte;
	int iInputValue;

	int iByteSize = 0;
	int iCount;

	iByteSize = sizeof(shData);
	
	while (1)
	{
		printf("��ġ(1~4) : ");
		scanf("%d", &iInputByte);

		printf("�� [0~255] : ");
		scanf("%d", &iInputValue);

		if ((iInputValue < 0) || (iInputValue > 255))
		{
			printf("���� ������ �ʰ��Ͽ����ϴ�. \n\n");
			continue;
		}

		switch (iInputByte)
		{
		case 1 :
		case 2 :
		case 3 :
		case 4 :
			shData = shData & ~(0xff << (iInputByte - 1) * 8);			//�ش� byte �ʱ�ȭ
			shData = shData | (iInputValue << (iInputByte - 1) * 8);		//�� �ֱ�
			break;
		default :
			printf("��Ʈ ������ �ʰ��Ͽ����ϴ�. \n\n");
			continue;
		}
		
		for (iCount = 0; iCount < iByteSize; iCount++)
		{
			shTemp = shData & (0xff << ((iByteSize - iCount - 1) * 8));

			printf("%d��° ����Ʈ �� : ", iByteSize - iCount);
			printf("%d", shTemp >> (iByteSize - iCount - 1) * 8);
			printf("\n");
		}
		printf("\n");
		printf("��ü 4����Ʈ �� : 0x%08x", shData);
		printf("\n\n");
	}
}
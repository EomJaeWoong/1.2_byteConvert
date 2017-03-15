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
		printf("위치(1~4) : ");
		scanf("%d", &iInputByte);

		printf("값 [0~255] : ");
		scanf("%d", &iInputValue);

		if ((iInputValue < 0) || (iInputValue > 255))
		{
			printf("값의 범위를 초과하였습니다. \n\n");
			continue;
		}

		switch (iInputByte)
		{
		case 1 :
		case 2 :
		case 3 :
		case 4 :
			shData = shData & ~(0xff << (iInputByte - 1) * 8);			//해당 byte 초기화
			shData = shData | (iInputValue << (iInputByte - 1) * 8);		//값 넣기
			break;
		default :
			printf("비트 범위를 초과하였습니다. \n\n");
			continue;
		}
		
		for (iCount = 0; iCount < iByteSize; iCount++)
		{
			shTemp = shData & (0xff << ((iByteSize - iCount - 1) * 8));

			printf("%d번째 바이트 값 : ", iByteSize - iCount);
			printf("%d", shTemp >> (iByteSize - iCount - 1) * 8);
			printf("\n");
		}
		printf("\n");
		printf("전체 4바이트 값 : 0x%08x", shData);
		printf("\n\n");
	}
}
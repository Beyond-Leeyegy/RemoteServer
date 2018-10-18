/*
	FILE :packet.cpp
	数据包处理函数

*/

#include "def.h"
#include "packet.h"
#include <cstring>

/*
在pPacket参数的nPos放置BYTE类型的value的值
*/
void  PutByte(char *pPacket, BYTE value, int & nPos) {
	
	*(BYTE *)(pPacket + nPos) = value;
	nPos += sizeof(BYTE);
}

/*
吧pPacket参数nPos位置的值以BYTE类型返回
*/

BYTE  GetByte(char* pPacket, int& nPos) {
	BYTE value = *(BYTE *)(pPacket + nPos);
	nPos += sizeof(BYTE);
	return value;
}


/*
在pPacket参数的nPos放置WORD类型的value的值
*/
void PutWord(char *pPacket, WORD value, int & nPos) {
	*(WORD *)(pPacket + nPos) = value;
	nPos += sizeof(WORD);
}

/*
吧pPacket参数nPos位置的值以WORD类型返回
*/

WORD GetWord(char* pPacket, int& nPos) {
	WORD value = *(WORD *)(pPacket + nPos);
	nPos += sizeof(WORD);
	return value;
}

/*
在pPacket参数的nPos放置DWORD类型的value的值
*/
void PutDword(char *pPacket, DWORD value, int & nPos) {
	*(DWORD *)(pPacket + nPos) = value;
	nPos += sizeof(DWORD);
}

/*
吧pPacket参数nPos位置的值以DWORD类型返回
*/

DWORD GetDword(char* pPacket, int &nPos) {
	DWORD value = *(DWORD *)(pPacket + nPos);
	nPos += sizeof(DWORD);
	return value;
}

/*
在pPacket参数的nPos放置int类型的value的值
*/
void  PutInteger(char *pPacket, int value, int & nPos) {
	*(int *)(pPacket + nPos) = value;
	nPos += sizeof(int);
}

/*
吧pPacket参数nPos位置的值以int类型返回
*/

int  GetInteger(char* pPacket, int &nPos) {
	int value = *(int*)(pPacket + nPos);
	nPos += sizeof(int );
	return value;
}

/*
在pPacket参数的nPos放置short类型的value的值
*/
void PutShort(char *pPacket, short value, int & nPos) {
	*(short *)(pPacket + nPos) = value;
	nPos += sizeof(short);
}

/*
吧pPacket参数nPos位置的值以short类型返回
*/

short GetShort(char* pPacket, int& nPos) {
	short value = *(short*)(pPacket + nPos);
	nPos += sizeof(short);
	return value;
}

/*
在pPacket参数的nPos放置字符串
*/
void PutString(char *pPacket, char *str, int & nPos) {
	*(WORD*)(pPacket + nPos) = strlen(str);
	nPos += sizeof(WORD);
	memcpy(pPacket + nPos, str, strlen(str));
	nPos += strlen(str);
}

/*
吧pPacket参数nPos位置的字符串复制到pBuffer（包括NULL的处理）
*/

void GetString(char* pPacket, char *pBuffer, int &nPos) {
	WORD length = *(WORD*)(pPacket + nPos);
	nPos += sizeof(WORD);
	memcpy(pBuffer, pPacket + nPos, length);
	*(pBuffer + length) = '\0';
	nPos += length;
}

/*
设置数据包的总长度:保存在数据包开始部分
*/
void PutSize(char *pPacket, WORD nPos) {
	*(WORD *)pPacket = nPos;
}

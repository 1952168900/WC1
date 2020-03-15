#include<stdio.h> 
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int Countcharacters(char File[]) { //�ַ������� 
	int characters = 0;
	FILE *file_Read = fopen(File,"rt");
	char chr = ' '; 
	if(file_Read == NULL) {
		printf("�ļ���ַ������ر�����\n");
		return 0; 
	}
	while((chr = fgetc(file_Read)) != EOF) {
		if(isspace(chr) == NULL)characters++;
	}
	fclose(file_Read);
	printf("�ַ�������%d\n",characters);
	return 1;
}

int Countwords(char File[]) {//����������
	int words = 0; 
	FILE *file_Read = fopen(File,"rt");
	char chr = ' '; 
	if(file_Read == NULL) {
		printf("�ļ���ַ������ر�����\n");
		return 0; 
	}
	while((chr = fgetc(file_Read)) != EOF) {
		while((chr >= 'a' && chr <= 'z' )|| (chr >= 'A' && chr <= 'Z')||chr == '-')
		 	chr = fgetc(file_Read);
		words++;	
	}
	fclose(file_Read);
	printf("�ļ�������Ϊ%d\n",words);
	return 1;
} 

int Countlines(char File[]) { //�������� 
	int lines = 0;
	int sign = 0;
	FILE *file_Read = fopen(File,"rt");
	char chr = ' '; 
	if(file_Read == NULL) {
		printf("�ļ���ַ������ر�����\n");
		return 0; 
	}
	while((chr = fgetc(file_Read)) != EOF) {
		if(sign == 0)lines++;
		sign++;
		if(chr == '\n')
			lines++;
	}
	fclose(file_Read);
	printf("ͳ������Ϊ%d\n",lines);
	return 1;
}

int main() {
	int  tag;
	char control;
	char File[100];
	int  number = 1;
	printf("\nָ���\nc ͳ���ַ�����w ͳ�Ƶ�������l ͳ������\nr �˳�����\n");
	printf("�������û�����wc.ext-:\n"); 
	scanf("%c",&control);
	printf("����ȷ����Ҫ���ҵ��ļ���ַ��\n"); 
	scanf("%s",File);
	while(number) {
		switch(control) {
			case 'c':tag=Countcharacters(File);
					 if(tag == 0)return 0;
					 break;
			case 'w':tag=Countwords(File);
					 if(tag == 0)return 0;
					 break;
			case 'l':tag=Countlines(File);
					 if(tag == 0)return 0;
					 break;
			case 'r':return 0;
			default :printf("�����������û�����wc.ext-:\n");
		}
		scanf("%c",&control); 
	}
}

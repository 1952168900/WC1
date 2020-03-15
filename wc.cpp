#include<stdio.h> 
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int Countcharacters(char File[]) { //字符数计算 
	int characters = 0;
	FILE *file_Read = fopen(File,"rt");
	char chr = ' '; 
	if(file_Read == NULL) {
		printf("文件地址错误，请关闭重试\n");
		return 0; 
	}
	while((chr = fgetc(file_Read)) != EOF) {
		if(isspace(chr) == NULL)characters++;
	}
	fclose(file_Read);
	printf("字符个数是%d\n",characters);
	return 1;
}

int Countwords(char File[]) {//单词数计算
	int words = 0; 
	FILE *file_Read = fopen(File,"rt");
	char chr = ' '; 
	if(file_Read == NULL) {
		printf("文件地址错误，请关闭重试\n");
		return 0; 
	}
	while((chr = fgetc(file_Read)) != EOF) {
		while((chr >= 'a' && chr <= 'z' )|| (chr >= 'A' && chr <= 'Z')||chr == '-')
		 	chr = fgetc(file_Read);
		words++;	
	}
	fclose(file_Read);
	printf("文件单词数为%d\n",words);
	return 1;
} 

int Countlines(char File[]) { //行数计算 
	int lines = 0;
	int sign = 0;
	FILE *file_Read = fopen(File,"rt");
	char chr = ' '; 
	if(file_Read == NULL) {
		printf("文件地址错误，请关闭重试\n");
		return 0; 
	}
	while((chr = fgetc(file_Read)) != EOF) {
		if(sign == 0)lines++;
		sign++;
		if(chr == '\n')
			lines++;
	}
	fclose(file_Read);
	printf("统计行数为%d\n",lines);
	return 1;
}

int main() {
	int  tag;
	char control;
	char File[100];
	int  number = 1;
	printf("\n指令表：\nc 统计字符数，w 统计单词数，l 统计行数\nr 退出程序\n");
	printf("请输入用户命令wc.ext-:\n"); 
	scanf("%c",&control);
	printf("请正确输入要查找的文件地址：\n"); 
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
			default :printf("请重新输入用户命令wc.ext-:\n");
		}
		scanf("%c",&control); 
	}
}

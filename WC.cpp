#include <stdio.h>
#include <string.h>
#include <iostream>

int Count(char flie[]);   //ͳ���ַ���
int	World(char file[]);   //ͳ�Ƶ�����
int Line( char file[]);   //ͳ������
int Blank(char file[]);
//int Code(char file[]);
int Explain(char file[]);


int main(){
	char in[2], file[10];
	while(1){
		printf("���û�������� WC exe -");
		scanf("%s",&in);
		if(in[0]=='c'){
			printf("�������ļ�����");
			scanf("%s",&file) ;
			int count=0;
			count=Count(file);
			printf("�ļ����ַ���Ϊ�� %d\n",count);
			continue;
		}
		if(in[0]=='w'){
			printf("�������ļ�����");
			scanf("%s",&file) ;
			int world=0;
			world=World(file);
			printf("�ļ�������Ϊ�� %d\n",world);
			continue;
		}
		if(in[0]=='l'){
			printf("�������ļ�����");
			scanf("%s",&file) ;
			int line=0;
			line=Line(file);
			printf("�ļ�����Ϊ�� %d\n",line);
			continue;
		}
		if(in[0]=='a'){
			printf("�������ļ�����");
			scanf("%s",&file) ;
			int blank,code,explain,line;
			blank=Blank(file),line=Line(file) ,explain=Explain(file);
			printf("�հ�����Ϊ�� %d\n",blank);
        	printf("��������Ϊ�� %d\n",line-blank);
        	printf("ע������Ϊ�� %d\n",explain);
			continue;			
		}
	}
	getchar();
system("pause"); 
}



int Count(char file[]){     //ͳ���ַ���
	FILE *fp;
	int count=0; 
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(1);
	}
    char a;
    a=fgetc(fp);
    	while (a != EOF){
        a=fgetc(fp);
		count++;
	}
	fclose(fp);
	return count;
}



int World(char file[]){
	FILE *fp;
	int count=0;
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(1);
	}
	
	char a;
	a=fgetc(fp);
	while(a!=EOF){
		if(a>='a'&&a<='z'||a>='A'&&a<='Z'||a>='0'&&a<='9'){
        	while(a>='a'&&a<='z'||a>='A'&&a<='Z'||a>='0'&&a<='9'){
        		a=fgetc(fp);
			}
			count++;
			a=fgetc(fp);
		}
		a=fgetc(fp);
	}
	fclose(fp);
    return count;
}



int Line(char file[]){
	FILE *fp;
	int count=0;
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(1);
	}
	char a ;
	a=fgetc(fp);
	while (a!=EOF){
		if(a=='\n'){
			count++;
			a=fgetc(fp);
		}
		else{
	 		a=fgetc(fp);
			}
		} 
	fclose(fp);
	return count+1; 
}


int Blank(char file[]){
	FILE *fp;
	int b=0;
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(1);
	}
	char a;
	a=fgetc(fp);
	while(a!=EOF){
		if(a=='\n'){
			a=fgetc(fp);
			if(a=='\n'){				
				b++;
			}
		}
		else{
			a=fgetc(fp);
		}
	}
	fclose(fp);
	return b;
}

/*
int Code(char file[]){
	FILE *fp;
	int c=0;
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(1);
	}
	char a;
	a=fgetc(fp);
	while(a!=EOF){
		if(a=='{'){
			a=fgetc(fp);
			if(a=='\n'){
				c++;
				a=fgetc(fp);
			} 
		}
		else if(a==';'){
			a=fgetc(fp);
			if(a=='\n'){
				c++;
				a=fgetc(fp);
			}
	}
		if(a=='}'){
			a=fgetc(fp);
			if(a=='\n'){
				c++;
				a=fgetc(fp);
			}
		}
		a=fgetc(fp);
		}
		fclose(fp);
		return c+1;
}  */

int Explain(char file[]){
	FILE *fp;
	int e=0;
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("Ѱ���ļ�ʧ��\n");
		exit(1);
	}
	char a;
	a=fgetc(fp);
		while(a!=EOF){
			if(a=='/'){
				a=fgetc(fp);
				if(a=='/'){
					e++;
					a=fgetc(fp);
				}
			}
		a=fgetc(fp);
		}
		fclose(fp);
		return e;
} 

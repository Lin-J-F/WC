#include <stdio.h>
#include <string.h>
#include <iostream>

int Count(char flie[]);   //统计字符数
int	World(char file[]);   //统计单词数
int Line( char file[]);   //统计行数
int Blank(char file[]);
//int Code(char file[]);
int Explain(char file[]);


int main(){
	char in[2], file[10];
	while(1){
		printf("请用户输入命令： WC exe -");
		scanf("%s",&in);
		if(in[0]=='c'){
			printf("请输入文件名：");
			scanf("%s",&file) ;
			int count=0;
			count=Count(file);
			printf("文件的字符数为： %d\n",count);
			continue;
		}
		if(in[0]=='w'){
			printf("请输入文件名：");
			scanf("%s",&file) ;
			int world=0;
			world=World(file);
			printf("文件单词数为： %d\n",world);
			continue;
		}
		if(in[0]=='l'){
			printf("请输入文件名：");
			scanf("%s",&file) ;
			int line=0;
			line=Line(file);
			printf("文件行数为： %d\n",line);
			continue;
		}
		if(in[0]=='a'){
			printf("请输入文件名：");
			scanf("%s",&file) ;
			int blank,code,explain,line;
			blank=Blank(file),line=Line(file) ,explain=Explain(file);
			printf("空白行数为： %d\n",blank);
        	printf("代码行数为： %d\n",line-blank);
        	printf("注释行数为： %d\n",explain);
			continue;			
		}
	}
	getchar();
system("pause"); 
}



int Count(char file[]){     //统计字符数
	FILE *fp;
	int count=0; 
	fp=fopen(file,"r");
	if(fp==NULL){
		printf("寻找文件失败\n");
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
		printf("寻找文件失败\n");
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
		printf("寻找文件失败\n");
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
		printf("寻找文件失败\n");
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
		printf("寻找文件失败\n");
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
		printf("寻找文件失败\n");
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

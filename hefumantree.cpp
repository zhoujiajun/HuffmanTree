#include<iostream.h>
#include<string.h>
typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **HuffmanCode;
void Select(HuffmanTree HT,int a,int &s1,int &s2)
{
	int b=10000;
	s1=1;
	for(int l=1;l<=a;l++)
	{if(HT[l].weight<b&&HT[l].parent==0)
	{b=HT[l].weight;s1=l;}
	}
	s2=1;
	b=10000;
	for(l=1;l<=a;l++)
	{if(HT[l].weight<b&&l!=s1&&HT[l].parent==0)  
	{b=HT[l].weight;s2=l;}
	}	
}
void CreatHuffmanTree(HuffmanTree &HT,int n)
{
	if(n<=1) return;
	int m=2*n-1,s1,s2;
	HT=new HTNode[m+1];
	for(int i=1;i<=m;++i)
	{HT[i].parent=0;HT[i].lchild=0;HT[i].rchild=0;}
	int a[26]={82,15,38,39,123,23,17,46,71,2,4,38,33,71,73,29,1,69,64,94,26,11,16,2,16,1};
	for(i=1;i<=n;++i)
	{HT[i].weight=a[i-1];}
	for(i=n+1;i<=m;++i)
	{
		Select(HT,i-1,s1,s2);
	    HT[s1].parent=i;HT[s2].parent=i;
	    HT[i].lchild=s1;HT[i].rchild=s2;
	    HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
}
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	int c,f,start;
	char *cd;
	HC=new char*[n+1];
    cd=new char[n];
	cd[n-1]='\0';
	for(int i=1;i<=n;++i)
	{
		start=n-1;
		c=i;f=HT[i].parent;
		while(f!=0)
		{--start;
		if(HT[f].lchild==c) 
		    cd[start]='0';
		else cd[start]='1';
		c=f;f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);
	}
	delete cd;
}
void Code(char s,HuffmanCode HC)
{
	int s3;
	char t[53]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	for(int h=0;h<=52;h++)
	{   if(t[h]==s)
			s3=h+1;
	}
	if(s3>=27)
	{s3=s3-26;}
	cout<<HC[s3];
}
void PrintTree(HuffmanTree HT,int m)
{	cout<<"下标"<<'\t'<<"权值"<<'\t'<<"父母"<<'\t'<<"左孩子"<<'\t'<<"右孩子"<<endl;	
	for(int c=1;c<=m;c++)
			{ cout<<c<<'\t'<<HT[c].weight<<'\t'<<HT[c].parent<<'\t'<<HT[c].lchild<<'\t'<<HT[c].rchild<<endl;}
}
void PrintCode(HuffmanCode HC,int n)
{			char t[28]={" abcdefghijklmnopqrstuvwxyz"};	
	for(int e=1;e<=n;e++)
			{cout<<t[e]<<'\t'<<HC[e]<<endl;}
}
void Transfer(HuffmanCode HC)
{		char str[10000];
		cout<<"请输入一篇文章："<<endl;
	    cin.getline(str,10000);
	    for(int a=0;str[a]!='\0';a++)
		{	if(str[a]==' ')
		     cout<<" ";
		    else if(str[a]==',')
				cout<<",";
			else if(str[a]=='.')
				cout<<".";
			else
		           Code(str[a],HC);}
		cout<<endl;
}
void SolveCode(HuffmanTree HT)  
{
		char code[10000];
		int a=51,i=0;
		char t[28]={" abcdefghijklmnopqrstuvwxyz"};;
		cout<<"请输入一段二进制码：（以##结束）"<<endl;
	    cin.getline(code,10000);
		for( ;code[i]!='#';)
		{
		
			for( ;HT[a].lchild!=0||HT[a].rchild!=0;i++)
		{
			if(code[i]==',') { cout<<",";}
			else if(code[i]=='.')  {cout<<".";}
			else if(code[i]==' ')   {cout<<" ";}
			else if(code[i]=='0')
			{a=HT[a].lchild;	}	
			else  {a=HT[a].rchild;}						
		}
		cout<<t[a];a=51;
		}
		cout<<endl;
}
void main()
{
	HuffmanTree HT;
	CreatHuffmanTree(HT,26);
	HuffmanCode HC;
	CreatHuffmanCode(HT,HC,26);
	cout<<"***********欢迎进入赫夫曼编译码系统**************"<<endl;
	cout<<"1、输出赫夫曼树                 2、输出赫夫曼编码"<<endl;
    cout<<"3、输入一篇文章进行编码   4、输入二进制串进行解码"<<endl;
	cout<<"                   5、退出系统                   "<<endl;
	for(int hfm; ; )
    {	cout<<"请输入您要使用的功能：";
		cin>>hfm;
		cin.ignore();
	if(hfm==5)   break;	
	switch(hfm)      
	{
	    case 1:
		    PrintTree(HT,51);break;
		case 2:
            PrintCode(HC,26);break;
		case 3:
            Transfer(HC);break;
        case 4:
			SolveCode(HT);break;
		default: cout<<"您的输入有误！"<<endl;
	}
	}  cout<<"谢谢您的使用！"<<endl;
}
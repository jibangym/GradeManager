#include<iostream>
using namespace std;
//结构体定义
struct person{
	char name[30];
	int ID;
	int grades;
} people[30];
//变量定义

int Pnumber;
char name[30];
char classname[30];
int grade;
int ID;
bool isChoosed=false,isnotChoosed=true;
//函数定义
void show(){
	cout<<Pnumber<<endl;
	if(Pnumber!=0){
		for(int i=0;i<=Pnumber-1;i++){
			cout<<"name:"<<people[i].name<<"\t";
			cout<<"grade:"<<people[i].grades<<endl;
			cout<<"ID:"<<people[i].ID<<endl;
			}
		}else{
		cout<<"There is no student.\n";
	}
	cout<<"show success.\n";
}
void choose(){
	cout<<"Please input your name:\t";
	cin>>name;
	cout<<"Please input your ID:\t";
	cin>>ID;
	cout<<Pnumber<<endl;
	for(int i=0;i<=(Pnumber-1);i++){//for只执行了1次
		if(ID==people[i].ID){
					cout<<"You has choosen the class.";
					isChoosed=true;
				}			
			}
	if(!isChoosed){
		person tem;
		for(int i = 0;i<=30;i++){
		tem.name[i] = name[i];
		}		
		tem.grades  = 0;
		people[Pnumber]=tem;
		people[Pnumber].ID=ID;
		Pnumber+=1;	
	}
	isChoosed=false;
	cout<<"choose succeed\n";
}

void cancel(){
	cout<<"Please input your ID:\t";
	cin>>ID;
	for(int i=0;i<=(Pnumber-1);i++){
		if(ID==people[i].ID){
			for(int j = i;j<=(Pnumber-2);j++){
				people[j]=people[j+1];
			}
		person tem;
		for(int i = 0;i<=30;i++){
		tem.name[i] = NULL;
		}		
		tem.grades  = 0;
		people[Pnumber-1]=tem;
		isnotChoosed=false;	
		Pnumber-=1;
		}			
			}
	if(isnotChoosed){
		cout<<"You have not choosed this class";
	}
	isnotChoosed=true;

	cout<<"cancel success\n";
	}

void input(){
	cout<<"Please input your ID:\t";
	cin>>ID;
	cout<<"Please input your grade:\t";
	cin>>grade;
	for(int i=0;i<=(Pnumber-1);i++){
		if(ID==people[i].ID){
			people[i].grades=grade;
			cout<<people[i].grades;
					isChoosed=true;
				}			
			}
	if(!isChoosed){
		cout<<"You have not choosed this class"<<endl;
	}
	isChoosed=false;

	cout<<"input\n";
}
//主函数
int main(){
	int action;
	Pnumber=0;
	for(int i=0;i<=30;i++){
		people[i].grades=0;
}
	while(1){
	cout<<"1-->Show the list\n";
	cout<<"2-->Choose your class\n";
	cout<<"3-->Cancel your class\n";
	cout<<"4-->Input your grades\n";
	cout<<"5-->Exit\n";	
		cout<<"Please input your command:\n";
		cin>>action;
		switch(action){
		case 1:show();break;
		case 2:choose();break;
		case 3:cancel();break;
		case 4:input();break;
		case 5: return 0;break;
		default: cout<<"Input Error!";
		}
	}
}

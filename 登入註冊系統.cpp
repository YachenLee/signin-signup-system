#include <fstream>
#include <iostream>
#include <string> 
using namespace std;

void signin(void);
void signup(void);

int main(){
   char s, a;
   cout << "�w��!\n" << "�n�J(I) �� ���U(U)\n" ;
   cin >> s;
   if(s=='I'){       //�P�_�n�Jor���U 
   	 signin();
   }
   if(s=='U'){
   	 signup(); 	
   }
}

void signin(){   //�n�J 
	string n, p, line, m;
	char a, b;
	int s, f=0, f2=0;
	
	fstream mem;
    fstream name;
	fstream pass;  
	
	cout << "�n�J�b��" << endl;
	cout << "�ϥΪ̦W��:" << " ";//��J�b�� 
	cin >> n;
   	
   	name.open("name.txt", ios::in);//�ˬd�O�_���ۦP�b�� 
	while (getline(name, line)){
        if(line == n){
        	f=1;	
		}	
    }
	name.close();
	if(f==0){//�p�G�S���o�ӱb�� 
		cout << "�d�L���b�� �� (�� u�� )�~" << endl;
		cout << "���s�n�J(I) �� ���U�b��(U)" << endl;
		cin >> a;
		if(a=='I'){
			signin();
		} 
		else if(a=='U'){
			return signup();
			
		}
	}
	if(f==1){//�������~���J�K�X 
		cout << "�K�X:" << " ";
   		cin >> p;
   		m = n+p;
   		
   		mem.open("member.txt", ios::in);//�ˬd�O�_���ۦP�b�� 
		while (getline(mem, line)){
        	if(line==m){
        	f2=1;
			}
		}
		if(f2==1){
			cout << "�n�J���� (((o(*^��^*)o)))" << endl << "�w��" << n << "!"; 
			
		}
		else{
			cout << "�K�X���~ �� (�E�עE)��" << endl;
			cout << "���s�n�J(I) �� ���U�b��(U)" << endl; 
			cin >> b;
			if(b=='I'){
				signin();
			}
			else if(b=='U'){
				return signup();
			}
		}
		
	    mem.close();
   		
	}
   	
}

void signup(){//���U 
	fstream mem;
    fstream name;
	fstream pass;  
	string n, p, line, p2;
	int f;
	char a, b;
	cout << "���U�b��" << endl;   //��J�b�K 
	cout << "�ϥΪ̦W��:" << " ";
	cin >> n;
	name.open("name.txt", ios::in);//��O�ƥ����O�_���ۦP�b�� 
	while (getline(name, line)) {
        if(line==n){
        	f=1;	
		}
    }
	name.close();
	
	if(f==1){
		cout << "�b���w�s�b ��(���㡫)�~" << endl;
		cout << "�n�J�{���b��(I) �� ���U�b��(U)" << endl;
		cin >> a;
		if(a=='U'){
			signup();
		}
		else if(a=='I'){
			return signin();
		}  
	}
	else{
		while(1){
			cout << "�K�X:" << " ";
   			cin >> p ;
   			cout << "�T�{�K�X:" << " ";
   			cin >> p2;
   			if(p==p2){
   				break;
			} 
   			cout << "��J���~�A�b�դ@�� (�á���;)!"<< endl; 
		}
		
   		
   			name.open("name.txt", ios::app);
    		if (!name.is_open()) {                  //���~���� 
        		cout << "Failed to open file.\n";
    		} 
			else {
        		name << n << "\n";    //�g�J�b�K 
    		}
    		name.close(); 
			
			pass.open("password.txt", ios::app);
    		if (!pass.is_open()) {                  //���~���� 
        		cout << "Failed to open file.\n";
    		} 
			else {
        		pass << p << "\n";    //�g�J�b�K 
    		}
    		pass.close();
		 	
			mem.open("member.txt", ios::app);
    		if (!mem.is_open()) {                  //���~���� 
        		cout << "Failed to open file.\n";
    		} 
			else {
        		mem << n << p << "\n";    //�g�J�b�K 
    		}
    		mem.close();
		
			cout << "���U���� (*��3`)~" << endl;
			cout << "�n�J(I) �� ���}(Z)" << endl;
			cin >> b;
			if(b=='I'){
				return signin();
			}	
			else if(b=='Z'){
				return;
			}
		}                       
    	
}


   

   



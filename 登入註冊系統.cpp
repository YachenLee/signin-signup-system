#include <fstream>
#include <iostream>
#include <string> 
using namespace std;

void signin(void);
void signup(void);

int main(){
   char s, a;
   cout << "歡迎!\n" << "登入(I) 或 註冊(U)\n" ;
   cin >> s;
   if(s=='I'){       //判斷登入or註冊 
   	 signin();
   }
   if(s=='U'){
   	 signup(); 	
   }
}

void signin(){   //登入 
	string n, p, line, m;
	char a, b;
	int s, f=0, f2=0;
	
	fstream mem;
    fstream name;
	fstream pass;  
	
	cout << "登入帳號" << endl;
	cout << "使用者名稱:" << " ";//輸入帳號 
	cin >> n;
   	
   	name.open("name.txt", ios::in);//檢查是否有相同帳號 
	while (getline(name, line)){
        if(line == n){
        	f=1;	
		}	
    }
	name.close();
	if(f==0){//如果沒有這個帳號 
		cout << "查無此帳號 ╮ (╯ u╰ )╭" << endl;
		cout << "重新登入(I) 或 註冊帳號(U)" << endl;
		cin >> a;
		if(a=='I'){
			signin();
		} 
		else if(a=='U'){
			return signup();
			
		}
	}
	if(f==1){//有的話繼續輸入密碼 
		cout << "密碼:" << " ";
   		cin >> p;
   		m = n+p;
   		
   		mem.open("member.txt", ios::in);//檢查是否有相同帳號 
		while (getline(mem, line)){
        	if(line==m){
        	f2=1;
			}
		}
		if(f2==1){
			cout << "登入完成 (((o(*^▽^*)o)))" << endl << "歡迎" << n << "!"; 
			
		}
		else{
			cout << "密碼錯誤 ╰ (〒皿〒)╯" << endl;
			cout << "重新登入(I) 或 註冊帳號(U)" << endl; 
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

void signup(){//註冊 
	fstream mem;
    fstream name;
	fstream pass;  
	string n, p, line, p2;
	int f;
	char a, b;
	cout << "註冊帳號" << endl;   //輸入帳密 
	cout << "使用者名稱:" << " ";
	cin >> n;
	name.open("name.txt", ios::in);//到記事本比對是否有相同帳號 
	while (getline(name, line)) {
        if(line==n){
        	f=1;	
		}
    }
	name.close();
	
	if(f==1){
		cout << "帳號已存在 ╮(′～‵)╭" << endl;
		cout << "登入現有帳號(I) 或 註冊帳號(U)" << endl;
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
			cout << "密碼:" << " ";
   			cin >> p ;
   			cout << "確認密碼:" << " ";
   			cin >> p2;
   			if(p==p2){
   				break;
			} 
   			cout << "輸入錯誤，在試一次 (￣□￣;)!"<< endl; 
		}
		
   		
   			name.open("name.txt", ios::app);
    		if (!name.is_open()) {                  //錯誤報錯 
        		cout << "Failed to open file.\n";
    		} 
			else {
        		name << n << "\n";    //寫入帳密 
    		}
    		name.close(); 
			
			pass.open("password.txt", ios::app);
    		if (!pass.is_open()) {                  //錯誤報錯 
        		cout << "Failed to open file.\n";
    		} 
			else {
        		pass << p << "\n";    //寫入帳密 
    		}
    		pass.close();
		 	
			mem.open("member.txt", ios::app);
    		if (!mem.is_open()) {                  //錯誤報錯 
        		cout << "Failed to open file.\n";
    		} 
			else {
        		mem << n << p << "\n";    //寫入帳密 
    		}
    		mem.close();
		
			cout << "註冊完成 (*′3`)~" << endl;
			cout << "登入(I) 或 離開(Z)" << endl;
			cin >> b;
			if(b=='I'){
				return signin();
			}	
			else if(b=='Z'){
				return;
			}
		}                       
    	
}


   

   



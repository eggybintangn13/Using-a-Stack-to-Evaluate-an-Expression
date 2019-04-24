#include <iostream>
using namespace std;

struct node{
	char element;
	node *next;
};

class stack{
  private:
		node *head=NULL;
  public:
    bool isEmpty(){
      if(head==NULL)
				return true;
			return false;
		}
    
    void pushtostack(char a){
			node *baru=new node;
			baru->element=a;
			baru->next=NULL;
			
      if(isEmpty()){
				head=baru;
			}
      else{
				baru->next=head;
				head=baru;
			}
		}
    
    char popfromstack(){
      if(isEmpty()){
				cout<<"Stack kosong!"<<endl;
				return 0;
			}
      else{
				char ch=head->element;
				node *tmp=head->next;
				delete head;
				head=tmp;
				return ch;
			}
		}
		
    char top(){
			return head->element;
		}
		
    void cetak(){
      if(isEmpty()){
				cout<<"Stack Kosong!";
			}
      else{
				node *bantu=head;
				while(bantu!=NULL){
					cout<<bantu->element<<endl;
					bantu=bantu->next;
				}
			}
		}
    
};

int cek(char cekoprtr){	
  if(cekoprtr=='*'||cekoprtr=='/')
	return 2;
	else
	return 1;
}

int main(){
	stack S;
	int i=0,n=0,A,B,C;
	char postfix[20];
	char infix[20];
  
	cin>>infix;
	
	while(infix[i]!='\0'){
    if(isdigit(infix[i])){
			postfix[n]=infix[i];
			n++;
		}
    
		else if(infix[i]=='('){
			S.pushtostack(infix[i]);
		}
    
		else if(infix[i]==')'){
			while(!S.isEmpty() && S.top()!='('){
				postfix[n]=S.popfromstack();
				n++;
			}
			S.popfromstack();
		}
    
		else{
			if(S.isEmpty() || S.top()=='('){
				S.pushtostack(infix[i]);
			}
      
			else{
				while(!S.isEmpty() && S.top()!='(' && cek(infix[i])<=cek(S.top())){
					postfix[n]=S.popfromstack();
					n++;
				}
				S.pushtostack(infix[i]);
			}
      
		}
		i++;
    
	}
  
	while(!S.isEmpty()){
		postfix[n]=S.popfromstack();
		n++;
	}
  
	/*postfix[n]='.';
	n=0;
	while(postfix[n]!='.'){
		cout<<postfix[n];
		n++;
	}
	cout<<endl;*/
  
  n=0;
  while(postfix[n]!='\0'){  
    if(isdigit(postfix[n])){
		  S.pushtostack(postfix[n]);
	  }
	  else{
		  A=S.popfromstack()-'0';
		  B=S.popfromstack()-'0';
		
		  if(postfix[n]=='*'){
			  C=B*A;
			  S.pushtostack(C+'0');
		  }
			
      else if(postfix[n]=='/'){
			  C=B/A;
			  S.pushtostack(C+'0');
		  }
			
      else if(postfix[n]=='+'){
			  C=B+A;
			  S.pushtostack(C+'0');	
		  }
			
      else if(postfix[n]=='-'){
			  C=B-A;
			  S.pushtostack(C+'0');
		  }
			
      else{
			  cout<<"Stack tidak ada"<<endl;
		  }
    
    }
	  n++;
  }
  
  cout<<S.popfromstack()-'0';
	
  return 0;
}

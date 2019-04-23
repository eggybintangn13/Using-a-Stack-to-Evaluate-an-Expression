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

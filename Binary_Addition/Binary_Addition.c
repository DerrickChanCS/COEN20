void AddBinary(int a[8], int b[8], int c[8]){
	int i = 0;
	int carry = 0;
	int sum;
	for(i = 0; i<8; i++){
		sum = a[i] + b[i] + carry;	
		if(sum == 2){
			carry = 1;
			c[i] = 0;
		}
		else{
			c[i] = sum;
			carry = 0;
		}
	}
}

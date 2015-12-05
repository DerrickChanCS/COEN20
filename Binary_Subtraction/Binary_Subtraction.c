void SubBinary(int a[8], int b[8], int c[8])
{
	int i = 0;
	int borrow = 0;
	int difference;

	for(i = 0; i<8; i++){
		difference = a[i] - b[i] - borrow;	
		if(difference < 0){
			borrow = 1;
			c[i] = difference + 2;
		}
		else{
			c[i] = difference;
			borrow = 0;
		}
	}
}

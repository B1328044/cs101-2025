int main(){

    char a[] = "A4B1C3f3";
    for(int i = 0; i<sizeof(a);i++)
    {
        if( a[i] >= '0' && a[i] <= '9' )
        {
            int count=a[i]-'0';
            for(int k = 0; k < count; k++)
            {
              printf("%c",a[i-1]);
            }
        }
    }

    return 0;

}

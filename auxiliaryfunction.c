#include <cstddef>

int ft_strlen(const char *size)  // Satırın uzunluğunu ölçmek için kullanacağım fonksiyon. Bu fonksiyonu satır da ki veriler buffer'ı aşmış mı aşmamış bunu öğrenmek için kullanabilirim. 
{
    int i; 

    i = 0;
    while (size[i])
    {
        i++;
    }
    return (i);
}


const char *strchr(const char *s, int c) // burada const tanımlamadık
{
    int i = 0;
    
    while (s[i] != '\0')  // burada koşul yanlıştı
    {
        if (s[i] == (char )c) // Burada char ile castlememiştik 
        {
           return (&s[i]); // Burada adresten itibarem döndürme yapmıyordun.  
        }
        
        i++;
    }

    return (NULL);
}


char	*ft_strjoin(char const *s1, char const *s2)

char *ft_strjoin(char const *s1, char const *s2)
{
 
    int 1i = 0;
    int 2i = 0;

    char new[] = malloc(char *s1 + s2);

    while(s1[i] == '/0')
    {
        new = s1[i];
        1++;  // Yani ben burada 1 stringin bitmesinden itibaren 2. indeksi yeni bir stringe atamak istiyorum 
    }

    while(s2[i] == '/0')
    {
        new = s2[i]; 
    }

    return new;


}





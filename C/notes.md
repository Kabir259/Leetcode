# From 0-43 no. video (25%)
## Fundamental Data types
![summary of basics](2024-10-02-14-49-31.png)
![](2024-10-02-14-51-08.png)
if you subtract 1 from int_min you will revert back to int_max and vice versa

![](2024-10-02-15-33-49.png)

![](2024-10-02-15-36-48.png) because on his comp size of int is 4 bytes, 1byte = 8bits, it gave **4294967295(INT_MAX for 4bit)**-2  = 4294967293,  
printed w/ %u, code will render the int acc to the size of int set on machine as shown in his output;  
howver if we did %d then it would render the true value of the arithmetic operation that is -3.

## char
![](image.png) char you can either initliase by giving 'a' or by its ascii val
size of char is 8bit and range is from:  
    unsigned = 0 to 255
    signed = -128 to 127

![](2024-10-02-15-02-24.png) signed me last bit is treated as negative only, usse pehle ki saari bits positive hoti hai. -128+1 -127 dega. thats how we represent -ve in signed.  
-1 will be rep in 8 bits as 1 1 1 1 1 1 1 1. 

acha and -128 == +128 as they are on the same position on the clock.  

in trad ascii table, char  = 7bits. in mdoern = 8 bits

![](2024-10-02-15-20-53.png) printf function not only prints in terminal but also returns no of chars it successfully printed. %d is caputing that.  
**output: Hello World!12**

![](2024-10-02-15-23-22.png) %10s means 10 length ka window print karega. Hello sirf 5 letterska hai to fir start me 5 blank spaces apni taraf se jodd dega.


## float
![](2024-10-02-15-10-54.png)

![](2024-10-02-15-16-58.png) float is precise to 8-1=7 decimals, double (rep by *l*) till 15 decimals and long double (rep by *L*) by 19 decimals. Do check how the are called while printing. 

# scope





   

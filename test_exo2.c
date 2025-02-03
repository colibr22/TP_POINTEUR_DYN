#include <stdio.h>

Const char* categorize_age(int age)  
{ 
    if (age < 0) { 
        return "Invalid age"; 
    }  
    else if (age < 13) { 
        return "Child"; 
    }  
    else if (age < 20) { 
        return "Teenager"; 
    }  
    else if (age < 65) { 
        return "Adult"; 
    }  
    else { 
        return "Senior"; 
    } 
} 
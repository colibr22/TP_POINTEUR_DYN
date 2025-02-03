#include <stdio.h>

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)

#define mu_run_test(test) do { const char *message = test(); tests_run++; if (message) return message; } while (0)

int tests_run = 0;

const char* categorize_age(int age)  
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

static char *test_age()
{
    const char* c = categorize_age(-1);
    mu_assert("assert failed", c == "Invalid age");
    return 0;
}
static char *test_age_enfant()
{
    const char* c = categorize_age(5);
    mu_assert("assert failed", c == "Child");
    return 0;
}
static char *test_age_ado()
{
    const char* c = categorize_age(16);
    mu_assert("assert failed", c == "Teenager");
    return 0;
}
static char *test_age_adult()
{
    const char* c = categorize_age(40);
    mu_assert("assert failed", c == "Adult");
    return 0;
}
static char *test_age_vieux()
{
    const char* c = categorize_age(70);
    mu_assert("assert failed", c == "Senior");
    return 0;
}

static char *all_tests() {
    mu_run_test(test_age);
    mu_run_test(test_age_enfant);
    mu_run_test(test_age_ado);
    mu_run_test(test_age_adult);
    mu_run_test(test_age_vieux);
    return 0;
}

int main(int argc, char **argv) {
    const char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

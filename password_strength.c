#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int score = 0;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline
    password[strcspn(password, "\n")] = 0;

    length = strlen(password);

    // Check password characters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    // Score rules
    if (length >= 8) score++;
    if (length >= 12) score++;
    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecial) score++;

    printf("\n--- Password Strength Report ---\n");
    printf("Length: %d characters\n", length);
    printf("Contains Uppercase: %s\n", hasUpper ? "Yes" : "No");
    printf("Contains Lowercase: %s\n", hasLower ? "Yes" : "No");
    printf("Contains Digits: %s\n", hasDigit ? "Yes" : "No");
    printf("Contains Special Characters: %s\n", hasSpecial ? "Yes" : "No");

    // Strength level
    printf("\nPassword Strength: ");
    if (score <= 2)
        printf("Weak\n");
    else if (score == 3 || score == 4)
        printf("Medium\n");
    else if (score == 5)
        printf("Strong\n");
    else
        printf("Very Strong\n");

    // --- Suggestions Section ---
    printf("\n--- Suggestions to Improve Your Password ---\n");

    if (length < 8)
        printf("• Increase length to at least 8 characters.\n");

    if (length < 12)
        printf("• For better security, use 12+ characters.\n");

    if (!hasUpper)
        printf("• Add at least one uppercase letter (A-Z).\n");

    if (!hasLower)
        printf("• Add at least one lowercase letter (a-z).\n");

    if (!hasDigit)
        printf("• Add at least one digit (0-9).\n");

    if (!hasSpecial)
        printf("• Add special characters like ! @ # $ %% ^ & *.\n");

    if (score >= 5)
        printf("• Your password is already strong! Maintain good habits.\n");

    return 0;
}

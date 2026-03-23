## 📌 Description
_printf is a custom implementation of the standard C printf function.
It formats and prints data to the standard output.

## ⚙️ Prototype
    
int _printf(const char *format, ...);
    

## 🔤 Supported Specifiers

| Specifier Description
|----------|------------|
| %c Character
| %s String
| %d, %i Integer
| %% Percent sign

## 🧠 How It Works

- Parses the format string
- Detects % specifiers
- Calls the corresponding handler function
- Prints output and returns character count

## 🔧 Compilation

gcc -Wall -Werror -Wextra -pedantic *.c -o printf
    
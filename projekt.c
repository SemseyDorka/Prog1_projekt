#include <stdio.h>
#include <string.h>
void option_print(char *template)
{
    if (strcmp(template, "c") == 0)
    {
        printf("#include <stdio.h>\n int main(){\n    printf(\"Hello world\\n\");\n return 0;}\n");
    }
    else if (strcmp(template, "s") == 0)
    {
        printf("#!/bin/bash\n echo \"Hello world\"\n");
    }
    else if (strcmp(template, "C") == 0)
    {
        printf("using System;\nclass Program \n{\n static void Main()\n {\n Console.WriteLine(\"Hello world\");\n } \n}\n");
    }
    else if (strcmp(template, "p") == 0)
    {
        printf("print(\"Hello world\\n\")");
    }
    else
    {
        printf("Invalid template\n");
    }
}
void option_help()
{
    printf("usage: alap <template> <option>\n Options:\n -h :help\n -p:  print result\n -f:create file\n");
    printf("Templates:\n c : C source code (main.c) \n s: Bash source code (main.sh)\n C : C# source code (Program.cs)\n p : Python source code (main.py) \n");
}
char *name(char *template)
{
    char *file_name;
    if (strcmp(template, "c") == 0)
    {
        file_name = "main.c";
    }
    else if (strcmp(template, "s") == 0)
    {
        file_name = "main.sh";
    }
    else if (strcmp(template, "C") == 0)
    {
        file_name = "program.cs";
    }
    else if (strcmp(template, "p") == 0)
    {
        file_name = "main.py";
    }
    return file_name;
}
void option_file(char *template)
{
    char *file_name = name(template);
    FILE *file = fopen(file_name, "w");
    if (file != NULL)
    {
        if (strcmp(template, "c") == 0)
        {
            fprintf(file, "#include <stdio.h>\n int main(){\n    printf(\"Hello world\\n\");\n return 0;}\n");
            printf("C program written to file: main.c\n");
        }
        else if (strcmp(template, "s") == 0)
        {
            fprintf(file, "#!/bin/bash\n echo \"Hello world\"\n");
            printf("Bash program written to file: main.sh\n");
        }
        else if (strcmp(template, "C") == 0)
        {
            fprintf(file, "using System;\nclass Program \n{\n static void Main()\n {\n Console.WriteLine(\"Hello world\");\n } \n}\n");
            printf("C# program written to file: main.cs\n");
        }
        else if (strcmp(template, "p") == 0)
        {
            fprintf(file, "print(\"Hello world\\n\")");
            printf("Python program written to file: program.py\n");
        }
        fclose(file);
    }
    else
    {
        printf("Error: Unable to open file for writing.\n");
    }
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        option_help();
    }
    else
    {
        char *template = argv[1];
        char *option = argv[2];

        if (strcmp(template, "-h") == 0 || strcmp(option, "-h") == 0)
        {
            option_help();
        }
        else if (strcmp(option, "-p") == 0)
        {
            option_print(template);
        }
        else if (strcmp(option, "-f") == 0)
        {
            option_file(template);
        }
        else
        {
            printf("Invalid option\n");
        }
    }
    return 0;
}

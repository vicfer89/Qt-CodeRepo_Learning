#ifndef ARGUMENTS_H
#define ARGUMENTS_H


class Arguments
{
public:
    Arguments(int argc = 0, char **argv = nullptr);
    void set_argc(int argc){ m_argc = argc; }
    void set_argv(char ** argv){ m_argv = argv; }
    int get_argc(void){ return m_argc; }
    char** get_argv(void) const { return m_argv; }
private:
    int m_argc;
    char **m_argv;
};

#endif // ARGUMENTS_H

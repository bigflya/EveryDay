template <>
string debug_rep(char *p)
{
    return debug_rep(string(p));

}


template <>
string debug_rep(const char *cp)
{

    return debug_rep(string(cp));
}
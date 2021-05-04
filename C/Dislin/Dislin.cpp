#include <stdio.h>
#include "dislin.h"

int main()
{
    int nya = 2800, i;
    char* ctit = "Pie Charts (PIEGRF)", cbuf[41];
    float  xray[5] = { 1.0, 2.5, 2.0, 2.7, 1.8 };

    scrmod("revers");
    setpag("da4p");
    metafl("cons");
    disini();
    pagera();
    complx();
    axslen(1600, 1000);
    titlin(ctit, 2);
    chnpie("both");

    legini(cbuf, 5, 8);
    leglin(cbuf, "FIRST", 1);
    leglin(cbuf, "SECOND", 2);
    leglin(cbuf, "THIRD", 3);
    leglin(cbuf, "FOURTH", 4);
    leglin(cbuf, "FIFTH", 5);

    patcyc(1, 7);
    patcyc(2, 4);
    patcyc(3, 13);
    patcyc(4, 3);
    patcyc(5, 5);

    for (i = 0; i < 2; i++)
    {
        axspos(250, nya - i * 1200);
        if (i == 1)
        {
            labels("data", "pie");
            labpos("external", "pie");
        }

        piegrf(cbuf, 1, xray, 5);

        if (i == 1)
        {
            height(50);
            title();
        }
        endgrf();
    }
    disfin();
    return 0;
}

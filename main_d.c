#include <stdio.h>
#include "libft/libft.h"
#include "data_gathering_abstraction/data_gathering.h"
#include "data_intrepretation/intrepretor.h"
#include "data_reading/data_read.h"

int main()
{
     printf("--test1--\n|%*.*d|\n", 1, 1, 1);
    ft_printf("|%*.*d|\n", -1, 1, 1);

    printf("--test2--\n|%*.*d|\n", -1, 1, 1);
   ft_printf("|%*.*d|\n", -1, 1, 1);

    printf("--test3--\n|%*.*d|\n", 1, -1, 1);
    ft_printf("|%*.*d|\n", 1, -1, 1);

    printf("--test4--\n|%*.*d|\n", 1, 1, -1);
    ft_printf("|%*.*d|\n", 1, 1, -1);

    printf("--test5--\n|%*.*d|\n", -1, -1, 1);
    ft_printf("|%*.*d|\n", -1, -1, 1);

    printf("--test6--\n|%*.*d|\n", 1, -1, -1);
    ft_printf("|%*.*d|\n", 1, -1, -1);

    printf("--test7--\n|%*.*d|\n", -1, -1, -1);
    ft_printf("|%*.*d|\n", -1, -1, -1);

    printf("--test8--\n|%*.*d|\n", 0, 0, 0);
    ft_printf("|%*.*d|\n", 0, 0, 0);

    printf("--test9--\n|%*.*d|\n", -1, 0, 1);
    ft_printf("|%*.*d|\n", -1, 0, 1);

    printf("--test10--\n|%*.*d|\n", 0, -1, -1);
    ft_printf("|%*.*d|\n", 0, -1, -1);

    printf("--test11--\n|%*.*d|\n", -1, -1, 0);
    ft_printf("|%*.*d|\n", -1, -1, 0);

    printf("--test12--\n|%*.*d|\n", 0, 0, -1);
    ft_printf("|%*.*d|\n", 0, 0, -1);

    printf("--test13--\n|%*.*d|\n", 5, 5, 1);
    ft_printf("|%*.*d|\n", 5, 5, 1);

    printf("--test14--\n|%*.*d|\n", -5, -5, 1);
    ft_printf("|%*.*d|\n", -5, -5, 1);

    printf("--test15--\n|%*.*d|\n", -5, 5, 1);
    ft_printf("|%*.*d|\n", -5, 5, 1);

    printf("--test16--\n|%*.*d|\n", 5, -5, 1);
    ft_printf("|%*.*d|\n", 5, -5, 1);

    printf("--test17--\n|%*.*d|\n", -5, 5, -15);
    ft_printf("|%*.*d|\n", -5, 5, -15);

    printf("--test18--\n|%*.*d|\n", 5, -5, -15);
 ft_printf("|%*.*d|\n", 5, -5, -15);

    printf("--test19--\n|%*.*d|\n", -15, -5, 1);
    ft_printf("|%*.*d|\n", -15, -5, 1);

    printf("--test20--\n|%*.*d|\n", 15, -5, 1);
    ft_printf("|%*.*d|\n", 15, -5, 1);

    printf("--test21--\n|%*.*d|\n", 5, -15, 1);
    ft_printf("|%*.*d|\n", 5, -15, 1);

    printf("--test22--\n|%*.*d|\n", -5, -15, 1);
    ft_printf("|%*.*d|\n", -5, -15, 1);

    printf("--test23--\n|%*.*d|\n", -15, -5, 0);
    ft_printf("|%*.*d|\n", -15, -5, 0);

   printf("--test24--\n|%*.*d|\n", 15, -5, -1);
    ft_printf("|%*.*d|\n", 15, -5, -1);

    printf("--test25--\n|%*.*d|\n", 5, -15, 0);
    ft_printf("|%*.*d|\n", 5, -15, 0);

  
    printf("--test26--\n|%*.*d|\n", -5, -15, -1);
    ft_printf("|%*.*d|\n", -5, -15, -1);

   printf("--test27--\n|%*.*d|\n", 5, -5, 1);
    ft_printf("|%*.*d|\n", 5, -5, 1);

    printf("--test28--\n|%*.*d|\n", 1, 1, 10);
    ft_printf("|%*.*d|\n", 1, 1, 10);

    printf("--test29--\n|%*.*d|\n", -1, 10, 1);
    ft_printf("|%*.*d|\n", -1, 10, 1);

    printf("--test30--\n|%*.*d|\n", 10, -1, 1);
    ft_printf("|%*.*d|\n", 10, -1, 1);

    printf("--test31--\n|%*.*d|\n", 1, 10, -1);
    ft_printf("|%*.*d|\n", 1, 10, -1);

    printf("--test32--\n|%*.*d|\n", -1, -10, 1);
    ft_printf("|%*.*d|\n", -1, -10, 1);

    printf("--test33--\n|%*.*d|\n", 1, 1, -21);
    ft_printf("|%*.*d|\n", 1, 1, -21);

    printf("--test34--\n|%*.*d|\n", -1, 1, 10);
    ft_printf("|%*.*d|\n", -1, 1, 10);

    printf("--test35--\n|%*.*d|\n", 1, -10, 10);
    ft_printf("|%*.*d|\n", 1, -10, 10);

    printf("--test36--\n|%*.*d|\n", 10, 10, -1);
    ft_printf("|%*.*d|\n", 10, 10, -1);

    printf("--test37--\n|%*.*d|\n", -1, -10, 1);
    ft_printf("|%*.*d|\n", -1, -10, 1);

    printf("--test38--\n|%*.*d|\n", -1, 10, 1);
    ft_printf("|%*.*d|\n", -1, 10, 1);

    printf("--test39--\n|%*.*d|\n", 1, -10, 1);
    ft_printf("|%*.*d|\n", 1, -10, 1);

    printf("--test40--\n|%*.*d|\n", 1, 10, -1);
    ft_printf("|%*.*d|\n", 1, 10, -1);

    printf("--test41--\n|%*.*d|\n", -10, -1, 10);
   ft_printf("|%*.*d|\n", -10, -1, 10);

    printf("--test42--\n|a%.0da|\n", 0);
   ft_printf("|a%.0da|\n", 0);

    printf("--test43--\n|%.7d|\n", 100);
    ft_printf("|%.7d|\n", 100);

    printf("--test44--\n|%5.7d|\n", 100);
    ft_printf("|%5.7d|\n", 100);

    printf("--test45--\n|a%.7da|\n", 100);
    ft_printf("|a%.7da|\n", 100);

    printf("--test46--\n|%.7d|\n", 100);
    ft_printf("|%.7d|\n", 100);

    printf("--test47--\n|%.7d|\n", -100);
    ft_printf("|%.7d|\n", -100);

    printf("--test48--\n|%5.7d|\n", -100);
    ft_printf("|%5.7d|\n", -100);

    printf("--test49--\n|%.7d|\n", 0);
    ft_printf("|%.7d|\n", 0);

    printf("--test48--\n|a%.7da|\n", 0);
    ft_printf("|a%.7da|\n", 0);

    printf("--test49--\n|%.15d|\n", -100);
    ft_printf("|%.15d|\n", -100);   

    printf("--test50--\n|%.15d|\n", 100);
    ft_printf("|%.15d|\n", 100); 

    printf("--test51--\n|%.3d|\n", 100);
    ft_printf("|%.3d|\n", 100);

    printf("--test52--\n|%.3d|\n", -100);
    ft_printf("|%.3d|\n", -100);

    printf("--test53--\n|a%.3da|\n", 100);
    ft_printf("|a%.3da|\n", 100);

    printf("--test54--\n|%.0d|\n", 0); 
    ft_printf("|%.0d|\n", 0); 

    printf("--test55--\n|%.3d|\n", 0);
     printf("|%.3d|\n", 0);

    printf("--test56--\n|a%.3da|\n", 0);
    ft_printf("|a%.3da|\n", 0);

    printf("--test57--\n|%.0d|\n", 100);
     ft_printf("|%.0d|\n", 100);

    printf("--test58--\n|%.0d|\n", 100);
    ft_printf("|%.0d|\n", 100);

    printf("--test59--\n|a%.0da|\n", 100);
    ft_printf("|a%.0da|\n", 100);

    printf("--test60--\n|%.0d|\n", 100);
    ft_printf("|%.0d|\n", 100);

    printf("--test61--\n|%.0d|\n", -100);
    ft_printf("|%.0d|\n", -100);

    printf("--test62--\n|%.0d|\n", -100);
    ft_printf("|%.0d|\n", -100);

    printf("--test63--\n|%.0d|\n", -100);
    ft_printf("|%.0d|\n", -100);

    printf("--test64--\n|%.0d|\n", 0);
    ft_printf("|%.0d|\n", 0);

    printf("--test65--\n|%.0d|\n", 0);
    ft_printf("|%.0d|\n", 0);

    //---------------------------------------------
    printf("--test66--\n|%2.3d|\n", 100);
    ft_printf("|%2.3d|\n", 100);

    printf("--test67--\n|%3.3d|\n", 100);
    ft_printf("|%3.3d|\n", 100);

    printf("--test67--\n|a%3.3da|\n", 100);
    ft_printf("|a%3.3da|\n", 100);

    printf("--test68--\n|%4.3d|\n", 100);
    ft_printf("|%4.3d|\n", 100);

    printf("--test69-\n|%2.3d|\n", -100);
    ft_printf("|%2.3d|\n", -100);

    printf("--test70--\n|%3.3d|\n", -100);
    ft_printf("|%3.3d|\n", -100);

    printf("--test71--\n|%4.3d|\n", -100);
    ft_printf("|%4.3d|\n", -100);

    printf("--test72--\n|%4.3d|\n", 0);
    ft_printf("|%4.3d|\n", 0);

    printf("--test73--\n|%1.3d|\n", 0);
    ft_printf("|%1.3d|\n", 0);

    printf("--test74--\n|%1.3d|\n", 0);
    ft_printf("|%1.3d|\n", 0);

    printf("--test75--\n|a%1.3da|\n", 0);
    ft_printf("|a%1.3da|\n", 0);

    printf("--test76--\n|%2.0d|\n", 100);
    ft_printf("|%2.0d|\n", 100);

    printf("--test77--\n|%3.0d|\n", 100);
    ft_printf("|%3.0d|\n", 100);

    printf("--test78--\n|a%3.0da|\n", 100);
    ft_printf("|a%3.0da|\n", 100);

    printf("--test79--\n|%4.0d|\n", 100);
    ft_printf("|%4.0d|\n", 100);

    printf("--test80--\n|%2.0d|\n", -100);
    ft_printf("|%2.0d|\n", -100);

    printf("--test81--\n|%3.0d|\n", -100);
    ft_printf("|%3.0d|\n", -100);

    printf("--test82--\n|%4.0d|\n", -100);
    ft_printf("|%4.0d|\n", -100);

    printf("--test83--\n|%4.0d|\n", 0);
    ft_printf("|%4.0d|\n", 0);

    printf("--test84--\n|%1.0d|\n", 0);
    ft_printf("|%1.0d|\n", 0);

    printf("--test85--\n|%4.d|\n", 100);
    ft_printf("|%4.d|\n", 100);

    printf("--test86--\n|%2.d|\n", -100);
    ft_printf("|%2.d|\n", -100);

    printf("--test87--\n|%3.d|\n", -100);
    ft_printf("|%3.d|\n", -100);

    printf("--test88--\n|%4.d|\n", -100);
    ft_printf("|%4.d|\n", -100);

    printf("--test89--\n|%4.d|\n", 0);
    ft_printf("|%4.d|\n", 0);

    printf("--test90--\n|%1.d|\n", 0);
    ft_printf("|%1.d|\n", 0);

    printf("--test91--\n|a%1.0da|\n", 0);
    ft_printf("|a%1.0da|\n", 0);

    printf("--test92--\n|%2.7d|\n", 100);
    ft_printf("|%2.7d|\n", 100);

    printf("--test93--\n|%15.7d|\n", 100);
    ft_printf("|%15.7d|\n", 100);

    printf("--test94--\n|a%3.7da|\n", 100);
    ft_printf("|a%3.7da|\n", 100);

    printf("--test95--\n|%4.7d|\n", 100);
    ft_printf("|%4.7d|\n", 100);

    printf("--test96--\n|%2.7d|\n", -100);
     ft_printf("|%2.7d|\n", -100);

    printf("--test97--\n|%3.7d|\n", -100);
    ft_printf("|%3.7d|\n", -100);

    printf("--test98--\n|%15.7d|\n", -100);
    ft_printf("|%15.7d|\n", -100);

    printf("--test99--\n|%4.7d|\n", 0);
    ft_printf("|%4.7d|\n", 0);

    printf("--test100--\n|%1.7d|\n", 0);
     ft_printf("|%1.7d|\n", 0);

    printf("--test101--\n|a%1.7da|\n", 0);
    ft_printf("|a%1.7da|\n", 0);


    printf("--test102--\n|%.*d|\n", 0, 0);
    ft_printf("|%.*d|\n", 0, 0);

    printf("--test103--\n|%.*d|\n", -5, 0);
    ft_printf("|%.*d|\n", -5, 0);

    printf("--test104--\n|%.*d|\n", 5, 0);
    ft_printf("|%.*d|\n", 5, 0);

    printf("--test105--\n|%.*d|\n", 1, 0);
    ft_printf("|%.*d|\n", 1, 0);

    printf("--test106--\n|%.*d|\n", -5, 5);
    ft_printf("|%.*d|\n", -5, 5);

    printf("--test107--\n|%.*d|\n", 5, -5);
    ft_printf("|%.*d|\n", 5, -5);

    printf("--test108--\n|%.*d|\n", 5, 5);
    ft_printf("|%.*d|\n", 5, 5);

    printf("--test109--\n|%.*d|\n", -5, -5);
    ft_printf("|%.*d|\n", -5, -5);

    printf("--test110--\n|%.*d|\n", 1, -1);
    ft_printf("|%.*d|\n", 1, -1);

    printf("--test111--\n|%.*d|\n", -1, 1);
    ft_printf("|%.*d|\n", -1, 1);

    printf("--test112--\n|%.*d|\n", 0, -5);
    ft_printf("|%.*d|\n", 0, -5);

    printf("--test113--\n|%.*d|\n", 0, 5);
    ft_printf("|%.*d|\n", 0, 5);
    
    printf("--test114--\n|%.*d|\n", 0, 1);
    ft_printf("|%.*d|\n", 0, 1);

    printf("--test115--\n|%.*d|\n", 0, -1);
    ft_printf("|%.*d|\n", 0, -1);

    printf("--test116--\n|%.*d|\n", -1, -1);
    ft_printf("|%.*d|\n", -1, -1);

    printf("--test117--\n|%.*d|\n", 1, 1);
    ft_printf("|%.*d|\n", 1, 1);

    printf("--test118--\n|%02.3d|\n", 100);
    ft_printf("|%02.3d|\n", 100);

    printf("--test119--\n|%03.3d|\n", 100);
    ft_printf("|%03.3d|\n", 100);

    printf("--test120--\na|%03.3d|a\n", 100);
    ft_printf("a|%03.3d|a\n", 100);

    printf("--test121--\n|%04.3d|\n", 100);
    ft_printf("|%04.3d|\n", 100);

    printf("--test122--\n|%*.*d|\n",14,10,-10);
    ft_printf("|%*.*d|\n",14,10,-10);

    printf("--test123--\n|%02.3d|\n", -100);
    ft_printf("|%02.3d|\n", -100);

    printf("--test124--\n|%03.3d|\n", -100);
    ft_printf("|%03.3d|\n", -100);

    printf("--test125--\n|%04.3d|\n", -100);
     ft_printf("|%04.3d|\n", -100);

    printf("--test126--\n|%04.3d|\n", 0);
    ft_printf("|%04.3d|\n", 0);

    printf("--test127--\n|%01.3d|\n", 0);
    ft_printf("|%01.3d|\n", 0);

    printf("--test128--\n|%05d|\n", 1);
    ft_printf("|%05d|\n", 1);

    printf("--test128--\n|%0.d|\n", 10);
    ft_printf("|%0.d|\n", 10);

    printf("--test129--\n|%0d|\n", 10);
    ft_printf("|%0d|\n", 10);


   printf("--test130--\n|%-.13d|\n", 1);
   ft_printf("|%-.13d|\n", 1);
    
    printf("--test131--\n|a%01.3da|\n", 0);
    ft_printf("|a%01.3da|\n", 0);


    printf("--test132--\n|%02.0d|\n", 100);
    ft_printf("|%02.0d|\n", 100);


    printf("--test133--\n|%03.0d|\n", 100);
    ft_printf("|%03.0d|\n", 100);

    printf("--test134--\n|a%03.0da|\n", 100);
    ft_printf("|a%03.0da|\n", 100);

    printf("--test135--\n|%04.0d|\n", 100);
    ft_printf("|%04.0d|\n", 100);


    printf("--test136--\n|%02.0d|\n", -100);
     ft_printf("|%02.0d|\n", -100);

    printf("--test137--\n|%03.0d|\n", -100);
    ft_printf("|%03.0d|\n", -100);

    printf("--test138--\n|%04.0d|\n", -100);
    ft_printf("|%04.0d|\n", -100);

    printf("--test139--\n|%04.0d|\n", 0);
    ft_printf("|%04.0d|\n", 0);

    printf("--test140--\n|%01.0d|\n", 0);
    ft_printf("|%01.0d|\n", 0);

    printf("--test141--\n|%04.d|\n", 100);
    ft_printf("|%04.d|\n", 100);

    printf("--test142--\n|%02.d|\n", -100);
    ft_printf("|%02.d|\n", -100);

    printf("--test143--\n|%03.d|\n", -100);
    ft_printf("|%03.d|\n", -100);

    printf("--test141--\n|%04.d|\n", -100);
    ft_printf("|%04.d|\n", -100);

    printf("--test142--\n|%04.d|\n", 0);
    ft_printf("|%04.d|\n", 0);

    printf("--test142--\n|%01.d|\n", 0);
    ft_printf("|%01.d|\n", 0);

    printf("--test143--\n|a%01.0da|\n", 0);
    ft_printf("|a%01.0da|\n", 0);

    
    printf("--test0144--\n|%015.7d|\n", 100);
    ft_printf("|%015.7d|\n", 100);

    ft_printf("--test144--\n|%02.7d|\n", 100);
    ft_printf("|%02.7d|\n", 100);

    printf("--test145--\n|a%03.7da|\n", 100);
    ft_printf("|a%03.7da|\n", 100);

    printf("--test146--\n|%04.7d|\n", 100);
    ft_printf("|%04.7d|\n", 100);

    printf("--test147--\n|%02.7d|\n", -100);
    ft_printf("|%02.7d|\n", -100);

    printf("--test148--\n|%03.7d|\n", -100);
    ft_printf("|%03.7d|\n", -100);

    printf("--test149--\n|%015.7d|\n", -100);
    ft_printf("|%015.7d|\n", -100);

    printf("--test150--\n|%04.7d|\n", 0);
    ft_printf("|%04.7d|\n", 0);

    printf("--test160--\n|%01.7d|\n", 0);
    ft_printf("|%01.7d|\n", 0);

    printf("--test161--\n|a%01.7da|\n", 0);
    ft_printf("|a%01.7da|\n", 0);


    printf("--test162--\n|%0.*d|\n", 0, 0);
    ft_printf("|%0.*d|\n", 0, 0);

    printf("--test163--\n|%0.*d|\n", 0, 0);
    ft_printf("|%0.*d|\n", 0, 0);

    printf("--test164--\n|%0.*d|\n", 5, 0);
    ft_printf("|%0.*d|\n", 5, 0);

    printf("--test165--\n|%0.*d|\n", 1, 0);
    ft_printf("|%0.*d|\n", 1, 0);

    printf("--test166--\n|%0.*d|\n", -5, 5);
    ft_printf("|%0.*d|\n", -5, 5);

    
    printf("--test167--\n|%0.*d|\n", 5, -5);
    ft_printf("|%0.*d|\n", 5, -5);

    printf("--test168--\n|%0.*d|\n", 5, 5);
    ft_printf("|%0.*d|\n", 5, 5);

    printf("--test169--\n|%0.*d|\n", -5, -5);
    ft_printf("|%0.*d|\n", -5, -5);

    printf("--test170--\n|%0.*d|\n", 1, -1);
    ft_printf("|%0.*d|\n", 1, -1);

    printf("--test171--\n|%0.*d|\n", -1, 1);
     ft_printf("|%0.*d|\n", -1, 1);

    printf("--test172--\n|%0.*d|\n", 0, -5);
    ft_printf("|%0.*d|\n", 0, -5);

    printf("--test173--\n|%0.*d|\n", 0, 5);
    ft_printf("|%0.*d|\n", 0, 5);

    printf("--test174--\n|%0.*d|\n", 0, 1);
    ft_printf("|%0.*d|\n", 0, 1);

    printf("--test175--\n|%0.*d|\n", 0, -1);
    ft_printf("|%0.*d|\n", 0, -1);

    printf("--test176--\n|%0.*d|\n", -1, -1);
    ft_printf("|%0.*d|\n", -1, -1);

    printf("--test177--\n|%0.*d|\n", 1, 1);
    ft_printf("|%0.*d|\n", 1, 1);



    
    printf("--test178--\n|%0*.*d|\n", 1, 1, 1);
    ft_printf("|%0*.*d|\n", 1, 1, 1);

    printf("--test179--\n|%0*.*d|\n", -1, 1, 1);
    ft_printf("|%0*.*d|\n", -1, 1, 1);

    printf("--test180--\n|%0*.*d|\n", 1, -1, 1);
    ft_printf("|%0*.*d|\n", 1, -1, 1);

    printf("-test181--\n|%0*.*d|\n", 1, 1, -1);
    ft_printf("|%0*.*d|\n", 1, 1, -1);

    printf("--test182--\n|%0*.*d|\n", -1, -1, 1);
    ft_printf("|%0*.*d|\n", -1, -1, 1);

    printf("--test183--\n|%0*.*d|\n", 1, -1, -1);
    ft_printf("|%0*.*d|\n", 1, -1, -1);

    printf("--test184--\n|%0*.*d|\n", -1, -1, -1);
    ft_printf("|%0*.*d|\n", -1, -1, -1);

    printf("--test185--\n|%0*.*d|\n", 0, 0, 0);
    ft_printf("|%0*.*d|\n", 0, 0, 0);

    printf("--test186--\n|%0*.*d|\n", -1, 0, 1);
    ft_printf("|%0*.*d|\n", -1, 0, 1);

    printf("--test187--\n|%0*.*d|\n", 0, -1, -1);
    ft_printf("|%0*.*d|\n", 0, -1, -1);

    printf("--test188--\n|%0*.*d|\n", -1, -1, 0);
    ft_printf("|%0*.*d|\n", -1, -1, 0);

    printf("--test189--\n|%0*.*d|\n", 0, 0, -1);
    ft_printf("|%0*.*d|\n", 0, 0, -1);

    printf("--test190--\n|%0*.*d|\n", 5, 5, 1);
    ft_printf("|%0*.*d|\n", 5, 5, 1);

    printf("--test191--\n|%0*.*d|\n", -5, -5, 1);
    ft_printf("|%0*.*d|\n", -5, -5, 1);

    printf("--test192--\n|%0*.*d|\n", -5, 5, 1);
    ft_printf("|%0*.*d|\n", -5, 5, 1);

    printf("--test193--\n|%0*.*d|\n", 5, -5, 1);
    ft_printf("|%0*.*d|\n", 5, -5, 1);

    printf("--test194--\n|%0*.*d|\n", -5, 5, -15);
    ft_printf("|%0*.*d|\n", -5, 5, -15);

    printf("--test195--\n|%0*.*d|\n", 5, -5, -15);
    ft_printf("|%0*.*d|\n", 5, -5, -15);

    printf("--test196--\n|%0*.*d|\n", -15, -5, 1);
    ft_printf("|%0*.*d|\n", -15, -5, 1);

    printf("--test197--\n|%0*.*d|\n", 15, -5, 1);
    ft_printf("|%0*.*d|\n", 15, -5, 1);

    printf("--test198--\n|%0*.*d|\n", 5, -15, 1);
    ft_printf("|%0*.*d|\n", 5, -15, 1);

    printf("--test199--\n|%0*.*d|\n", -5, -15, 1);
    ft_printf("|%0*.*d|\n", -5, -15, 1);

    printf("--test200--\n|%0*.*d|\n", -15, -5, 0);
     ft_printf("|%0*.*d|\n", -15, -5, 0);

    printf("--test201--\n|%0*.*d|\n", 15, -5, -1);
    ft_printf("|%0*.*d|\n", 15, -5, -1);

    printf("--test202--\n|%0*.*d|\n", 5, -15, 0);
    ft_printf("|%0*.*d|\n", 5, -15, 0);

    printf("--test203--\n|%0*.*d|\n", -5, -15, -1);
    ft_printf("|%0*.*d|\n", -5, -15, -1);

    printf("--test204--\n|%0*.*d|\n", 5, -5, 1);
    ft_printf("|%0*.*d|\n", 5, -5, 1);

    printf("--test205--\n|%0*.*d|\n", 1, 1, 10);
    ft_printf("|%0*.*d|\n", 1, 1, 10);

    printf("--test206--\n|%0*.*d|\n", -1, 10, 1);
    ft_printf("|%0*.*d|\n", -1, 10, 1);

    printf("--test207--\n|%0*.*d|\n", 10, -1, 1);
    ft_printf("|%0*.*d|\n", 10, -1, 1);

    printf("--test208--\n|%0*.*d|\n", 1, 10, -1);
    ft_printf("|%0*.*d|\n", 1, 10, -1);

    printf("--test209--\n|%0*.*d|\n", -1, -10, 1);
    ft_printf("|%0*.*d|\n", -1, -10, 1);

    printf("--test210--\n|%0*.*d|\n", 1, 1, -21);
    ft_printf("|%0*.*d|\n", 1, 1, -21);

    printf("--test211--\n|%0*.*d|\n", -1, 1, 10);
    ft_printf("|%0*.*d|\n", -1, 1, 10);

    printf("--test212--\n|%0*.*d|\n", 1, -10, 10);
    ft_printf("|%0*.*d|\n", 1, -10, 10);

    printf("--test213--\n|%0*.*d|\n", 10, 10, -1);
    ft_printf("|%0*.*d|\n", 10, 10, -1);

    printf("--test214--\n|%0*.*d|\n", -1, -10, 1);
    ft_printf("|%0*.*d|\n", -1, -10, 1);

    
    printf("--test215--\n|%0*.*d|\n", 1, -10, 1);
    ft_printf("|%0*.*d|\n", 1, -10, 1);

    printf("--test216--\n|%0*.*d|\n", 1, 10, -1);
    ft_printf("|%0*.*d|\n", 1, 10, -1);

    printf("--test217--\n|%0*.*d|\n", -10, -1, 10);
    ft_printf("|%0*.*d|\n", -10, -1, 10);

   
    

    printf("--test223--\n|%5.d|\n", 5);
     ft_printf("|%5.d|\n", 5);

    printf("--test224--\n|%-5.d|\n", 5);
    ft_printf("|%-5.d|\n", 5);

    printf("--test225--\n|%0.d|\n", 5);
    ft_printf("|%0.d|\n", 5);

    printf("--test226--\n|%1.d|\n", 5);
    ft_printf("|%1.d|\n", 5);

    printf("--test227--\n|%.d|\n", 5);
    ft_printf("|%.d|\n", 5);

    printf("--test228--\n|%5.d|\n", -5);
    ft_printf("|%5.d|\n", -5);

    printf("--test229--\n|%-5.d|\n", -5);
    ft_printf("|%-5.d|\n", -5);

    printf("--test230--\n|%0.d|\n", -5);
    ft_printf("|%0.d|\n", -5);

    printf("--test231--\n|%1.d|\n", -5);
    ft_printf("|%1.d|\n", -5);

    printf("--test232--\n|%.d|\n", -5);
     ft_printf("|%.d|\n", -5);

  

    printf("--test237--\n|%*.d|\n", 0, 5);
   ft_printf("|%*.d|\n", 0, 5);

    printf("--test238--\n|%*.d|\n", 1, -5);
   ft_printf("|%*.d|\n", 1, -5);

    printf("--test239--\n|%*.d|\n", -0, 5);
   ft_printf("|%*.d|\n", -0, 5);

    printf("--test240--\n|%*.d|\n", -5, 5);
     ft_printf("|%*.d|\n", -5, 5);

    printf("--test241--\n|%*.d|\n", 1, 5);
    ft_printf("|%*.d|\n", 1, 5);

    printf("--test242--\n|%*.d|\n", -5, -5);
    ft_printf("|%*.d|\n", -5, -5);


    
    

    printf("--test248--\n|%05.d|\n", 5);
    ft_printf("|%05.d|\n", 5);

    printf("--test249--\n|%05.d|\n", 5);
    ft_printf("|%05.d|\n", 5);

    printf("--test250--\n|%00.d|\n", 5);
    ft_printf("|%00.d|\n", 5);

    printf("--test251--\n|%01.d|\n", 5);
    ft_printf("|%01.d|\n", 5);

    printf("--test252--\n|%0.d|\n", 5);
    ft_printf("|%0.d|\n", 5);

    printf("--test253--\n|%05.d|\n", -5);
    ft_printf("|%05.d|\n", -5);

    printf("--test254--\n|%05.d|\n", -5);
    ft_printf("|%05.d|\n", -5);

    printf("--test255--\n|%00.d|\n", -5);
    ft_printf("|%00.d|\n", -5);

    printf("--test256--\n|%01.d|\n", -5);
   ft_printf("|%01.d|\n", -5);

    printf("--test257--\n|%0.d|\n", -5);
   ft_printf("|%0.d|\n", -5);

  

    

    printf("|--test262--\n|%0*.d|\n", 0, 5);
   ft_printf("|%0*.d|\n", 0, 5);

    printf("--test263--\n|%0*.d|\n", 1, -5);
    ft_printf("|%0*.d|\n", 1, -5);

    printf("--test264--\n|%0*.d|\n", -0, 5);
   ft_printf("|%0*.d|\n", -0, 5);

    printf("--test265--\n|%0*.d|\n", -5, 5);
    ft_printf("|%0*.d|\n", -5, 5);

    printf("--test266--\n|%0*.d|\n", 1, 5);
    ft_printf("|%0*.d|\n", 1, 5);

    printf("--test267--\n|%0*.d|\n", -5, -5);
    ft_printf("|%0*.d|\n", -5, -5);

    printf("--test--\n|%0*.d|\n",10,42);
    ft_printf("|%0*.d|\n",10,42);

   printf("\n******************************************\n");

     printf("--test--\n|%0*.d|\n",5,42);
    ft_printf("|%0*.d|\n",5,42);


 printf("\n******************************************\n");
   printf("\n******************************************\n");

    printf("--test2--\n|%0*.d|\n", 5, 0);
     ft_printf("|%0*.d|\n", 5, 0);

       printf("--test3--\n|%0*.d|\n", -5, 0);
     ft_printf("|%0*.d|\n", -5, 0);

        printf("--test4--\n|%0*d|\n", 5, 42);
     ft_printf("|%0*d|\n", 5, 42);

       printf("--test5--\n|%0*d|\n", -5, 42);
     ft_printf("|%0*d|\n", -5, 42);

     printf("--test8--\n|%0d|\n", 0);
     ft_printf("|%0d|\n", 0);

     printf("--test8--\n|%0*d|\n", -5, 0);
     ft_printf("|%0*d|\n", -5, 0);

     printf("--test6--\n|%*.d|\n", 5, 0);
     ft_printf("|%*.d|\n", 5, 0);


   printf("--test7--\n|%05.d|\n", 0);
    ft_printf("|%05.d|\n", 0);

    printf("--test8--\n|%00.d|\n", 0);
    ft_printf("|%00.d|\n", 0);

    printf("--test9--\n|%01.d|\n", 0);
    ft_printf("|%01.d|\n", 0);
   
      printf("--test10--\n|%-*.d|\n",5,-42);
    ft_printf("|%-*.d|\n", 5,-42);
 

     printf("--test10--\n|%-*.d|\n",-5,-42);
    ft_printf("|%-*.d|\n",-5,-42);


      printf("--test10--\n|%05d|\n",-42);
    ft_printf("|%05d|\n",-42);
 printf("\n------------\n");
    printf("--test10--\n|%5d|\n",-42);
    ft_printf("|%5d|\n",-42);
printf("\n------------\n");
      printf("--test11--\n|%0*.d|\n", 0, 0);
   ft_printf("|%0*.d|\n", 0, 0);

   printf("--test12--\n|%05.d|\n", 0);
    ft_printf("|%05.d|\n", 0);

  

    printf("--test13--\n|%0.d|\n", 0);
   ft_printf("|%0.d|\n", 0);

   printf("--test14--\n|%0*.d|\n", -5, 0);
    ft_printf("|%0*.d|\n", -5, 0);

  

    printf("--test15--\n|%0*.d|\n", 1, 1);
     ft_printf("|%0*.d|\n", 1, 1);


      printf("--test16--\n|%*.d|\n", 0, 0);
    ft_printf("|%*.d|\n", 0, 0);

    printf("--test17--\n|%*.d|\n", -5, 0);
    ft_printf("|%*.d|\n", -5, 0);

    printf("--test18--\n|%*.d|\n", 5, 0);
    ft_printf("|%*.d|\n", 5, 0);

    printf("--test19--\n|%*.d|\n", 1, 0);
    ft_printf("|%*.d|\n", 1, 0);

    printf("--test20--\n|%5.d|\n", 0);
    ft_printf("|%5.d|\n", 0);

    printf("--test21--\n|%-5.d|\n", 0);
    ft_printf("|%-5.d|\n", 0);

    printf("--test22--\n|%0.d|\n", 0);
    ft_printf("|%0.d|\n", 0);

    printf("--test23--\n|%1.d|\n", 0);
    ft_printf("|%1.d|\n", 0);

    printf("--test24--\n|%.d|\n", 0);
     ft_printf("|%.d|\n", 0);

 printf("--test24--\n|%-*.*d|\n", 5,-5,42);
     ft_printf("|%-*.*d|\n", 5,-5,42);



printf("|%5.d|\n",5);

printf("|%05.d|\n",5);
printf("|%05d|\n",5);

printf("|%-5.d|\n",5);

  /*  
    printf("\n***********************\n");

    printf("|%2s|\n", "ABC");//|ABC|
    printf("|%3s|\n", "ABC");//|ABC|
    printf("|%4s|\n", "ABC");//| ABC|
    printf("|a%4sa|\n", "ABC");//|a ABCa|
    printf("|%1s|\n", NULL);//|(null)|
    printf("|a%1sa|\n", NULL);//|a(null)a|
    printf("|%6s|\n", NULL);
    printf("|%7s|\n", NULL);
    printf("|%4s|\n", "");
    printf("|%1s|\n", "");
    printf("|a%1sa|\n", "");

    printf("\n***********************\n");

    printf("%-2s\n", "ABC");
    printf("%-3s\n", "ABC");
    printf("%-4s\n", "ABC");
    printf("a%-4sa\n", "ABC");
    printf("%-1s\n", NULL);
    printf("a%-1sa\n", NULL);
    printf("%-6s\n", NULL);
    printf("%-7s\n", NULL);
    printf("%-4s\n", "");
    printf("%-1s\n", "");
    printf("a%-1sa\n", "");

    printf("\n***********************\n");


    printf("%2.3s", "ABC");
    printf("%3.3s", "ABC");
    printf("%4.3s", "ABC");
    printf("a%4.3sa", "ABC");
    printf("%1.3s", NULL);
    printf("a%1.3sa", NULL);
    printf("%6.3s", NULL);
    printf("%7.3s", NULL);
    printf("%4.3s", "");
    printf("%1.3s", "");
    T("a%1.3sa", "");
    T("%2.2s", "ABC");
    T("%3.2s", "ABC");
    T("%4.2s", "ABC");
    T("a%4.2sa", "ABC");
    T("%1.2s", NULL);
    T("a%1.2sa", NULL);
    T("%6.2s", NULL);
    T("%7.2s", NULL);
    T("%4.2s", "");
    T("%1.2s", "");
    T("a%1.2sa", "");
    T("%2.10s", "ABC");
    T("%3.10s", "ABC");
    T("%4.10s", "ABC");
    T("a%4.10sa", "ABC");
    T("%1.10s", NULL);
    T("a%1.10sa", NULL);
    T("%6.10s", NULL);
    T("%7.10s", NULL);
    T("%4.10s", "");
    T("%1.10s", "");
    T("a%1.10sa", "");
    T("%2.s", "ABC");
    T("%3.s", "ABC");
    T("%4.s", "ABC");
    T("a%4.sa", "ABC");
    T("%1.s", NULL);
    T("a%1.sa", NULL);
    T("%6.s", NULL);
    T("%7.s", NULL);
    T("%4.s", "");
    T("%1.s", "");
    T("a%1.sa", "");

*/
   /*
    T("%.3s", "ABC");
    T("%.3s", "ABC");
    T("%.3s", "ABC");
    T("a%.3sa", "ABC");
    T("%.3s", NULL);
    T("a%.3sa", NULL);
    T("%.3s", NULL);
    T("%.3s", NULL);
    T("%.3s", "");
    T("%.3s", "");
    T("a%.3sa", "");
    T("%.2s", "ABC");
    T("%.2s", "ABC");
    T("%.2s", "ABC");
    T("a%.2sa", "ABC");
    T("%.2s", NULL);
    T("a%.2sa", NULL);
    T("%.2s", NULL);
    T("%.2s", NULL);
    T("%.2s", "");
    T("%.2s", "");
    T("a%.2sa", "");
    T("%.10s", "ABC");
    T("%.10s", "ABC");
    T("%.10s", "ABC");
    T("a%.10sa", "ABC");
    T("%.10s", NULL);
    T("a%.10sa", NULL);
    T("%.10s", NULL);
    T("%.10s", NULL);
    T("%.10s", "");
    T("%.10s", "");
    T("a%.10sa", "");
    T("%.s", "ABC");
    T("%.s", "ABC");
    T("%.s", "ABC");
    T("a%.sa", "ABC");
    T("%.s", NULL);
    T("a%.sa", NULL);
    T("%.s", NULL);
    T("%.s", NULL);
    T("%.s", "");
    T("%.s", "");
    T("a%.sa", "");

      T("%*.3s", 5, "ABC");
    T("%*.3s", 5, "ABC");
    T("%*.3s", 5, "ABC");
    T("a%*.3sa", 5, "ABC");
    T("%*.3s", 5, NULL);
    T("a%*.3sa", 5, NULL);
    T("%*.3s", 5, NULL);
    T("%*.3s", 5, NULL);
    T("%*.3s", 5, "");
    T("%*.3s", 5, "");
    T("a%*.3sa", 5, "");
    T("%*.2s", 5, "ABC");
    T("%*.2s", 5, "ABC");
    T("%*.2s", 5, "ABC");
    T("a%*.2sa", 5, "ABC");
    T("%*.3s", 0, "ABC");
    T("%*.3s", 0, "ABC");
    T("%*.3s", 0, "ABC");
    T("a%*.3sa", 0, "ABC");
    T("%*.3s", 0, NULL);
    T("a%*.3sa", 0, NULL);
    T("%*.3s", 0, NULL);
    T("%*.3s", 0, NULL);
    T("%*.3s", 0, "");
    T("%*.3s", 0, "");
    T("a%*.3sa", 0, "");
    T("%*.2s", 0, "ABC");
    T("%*.2s", 0, "ABC");
    T("%*.2s", 0, "ABC");
    T("a%*.2sa", 0, "ABC");
    T("%*.3s", -15, "ABC");
    T("%*.3s", -15, "ABC");
    T("%*.3s", -15, "ABC");
    T("a%*.3sa", -15, "ABC");
    T("%*.3s", -15, NULL);
    T("a%*.3sa", -15, NULL);
    T("%*.3s", -15, NULL);
    T("%*.3s", -15, NULL);
    T("%*.3s", -15, "");
    T("%*.3s", -15, "");
    T("a%*.3sa", -15, "");
    T("%*.2s", -15, "ABC");
    T("%*.2s", -15, "ABC");
    T("%*.2s", -15, "ABC");
    T("a%*.2sa", -15, "ABC");

      T("%.*s", 5, "ABC");
    T("%.*s", 5, "ABC");
    T("%.*s", 5, "ABC");
    T("a%.*sa", 5, "ABC");
    T("%.*s", 5, NULL);
    T("a%.*sa", 5, NULL);
    T("%.*s", 5, NULL);
    T("%.*s", 5, NULL);
    T("%.*s", 5, "");
    T("%.*s", 5, "");
    T("a%.*sa", 5, "");
    T("%.*s", 5, "ABC");
    T("%.*s", 5, "ABC");
    T("%.*s", 5, "ABC");
    T("a%.*sa", 5, "ABC");
    T("%.*s", -5, "ABC");
    T("%.*s", -5, "ABC");
    T("%.*s", -5, "ABC");
    T("a%.*sa", -5, "ABC");
    T("%.*s", -5, NULL);
    T("a%.*sa", -5, NULL);
    T("%.*s", -5, NULL);
    T("%.*s", -5, NULL);
    T("%.*s", -5, "");
    T("%.*s", -5, "");
    T("a%.*sa", -5, "");
    T("%.*s", -5, "ABC");
    T("%.*s", -5, "ABC");
    T("%.*s", -5, "ABC");
    T("a%.*sa", -5, "ABC");
    T("%*.*s", 3,0, "ABC");
    T("%*.*s", 3,0, "ABC");
    T("%*.*s", 3,0, "ABC");
    T("a%*.*sa", 3,0, "ABC");
    T("%*.*s", 7,2, NULL);
    T("a%*.*sa", 7,2, NULL);
    T("%*.*s", 7,2, NULL);
    T("%*.*s", 7,2, NULL);
    T("%*.*s", 7,2, "");
    T("%*.*s", 7,2, "");

    T("a%*.*sa", 2,7, "");
    T("%*.*s", 2,7, "ABC");
    T("%*.*s", 2,7, "ABC");
    T("%*.*s", 2,7, "ABC");
    T("a%*.*sa", 2,7, "ABC");
    T("%*.*s", 3,4, "ABC");
    T("%*.*s", 3,4, "ABC");
    T("%*.*s", 3,4, "ABC");
    T("a%*.*sa", 3,4, "ABC");
    T("%*.*s", 3,4, NULL);
    T("a%*.*sa", 3,4, NULL);
    T("%*.*s", 3,4, NULL);
    T("%*.*s", 3,4, NULL);
    T("%*.*s", 3,4, "");
    T("%*.*s", 3,4, "");
    T("a%*.*sa", 3,4, "");
    T("%*.*s", 3,4, "ABC");
    T("%*.*s", 3,4, "ABC");
    T("%*.*s", 3,4, "ABC");
    T("a%*.*sa", 3,4, "ABC");
    T("%*.*s", 4,3, "ABC");
    T("%*.*s", 4,3, "ABC");
    T("%*.*s", 4,3, "ABC");
    T("a%*.*sa", 4,3, "ABC");
    T("%*.*s", 4,3, NULL);
    T("a%*.*sa", 4,3, NULL);
    T("%*.*s", 4,3, NULL);
    T("%*.*s", 4,3, NULL);
    T("%*.*s", 4,3, "");
    T("%*.*s", 4,3, "");
    T("a%*.*sa", 4,3, "");
    T("%*.*s", 4,3, "ABC");
    T("%*.*s", 4,3, "ABC");
    T("%*.*s", 4,3, "ABC");
    T("a%*.*sa", 4,3, "ABC");
    T("%*.*s", 0,0, "ABC");
    T("%*.*s", 0,0, "ABC");
    T("%*.*s", 0,0, "ABC");
    T("a%*.*sa", 0,0, "ABC");
    T("%*.*s", 0,0, NULL);
    T("a%*.*sa", 0,0, NULL);
    T("%*.*s", 0,0, NULL);
    T("%*.*s", 0,0, NULL);
    T("%*.*s", 0,0, "");
    T("%*.*s", 0,0, "");
    T("a%*.*sa", 0,0, "");
    T("%*.*s", 0,0, "ABC");
    T("%*.*s", 0,0, "ABC");
    T("%*.*s", 0,0, "ABC");
    T("a%*.*sa", 0, 0, "ABC");
    T("%*.*s", -7,-2, "ABC");
    T("%*.*s", -7,-2, "ABC");
    T("%*.*s", -7,-2, "ABC");
    T("a%*.*sa", -7,-2, "ABC");
    T("%*.*s", -7,-2, NULL);
    T("a%*.*sa", -7,-2, NULL);


    T("a%*.*sa", -7,-2, NULL);
    T("%*.*s", -7,-2, NULL);
    T("%*.*s", -7,-2, NULL);
    T("%*.*s", -7,-2, "");
    T("%*.*s", -7,-2, "");
    T("a%*.*sa", -7,-2, "");
    T("%*.*s", -7,-2, "ABC");
    T("%*.*s", -7,-2, "ABC");
    T("%*.*s", -7,-2, "ABC");
    T("a%*.*sa", -7,-2, "ABC");
    T("%*.*s", -2,-7, "ABC");
    T("%*.*s", -2,-7, "ABC");
    T("%*.*s", -2,-7, "ABC");
    T("a%*.*sa", -2,-7, "ABC");
    T("%*.*s", -2,-7, NULL);
    T("a%*.*sa", -2,-7, NULL);
    T("%*.*s", -2,-7, NULL);
    T("%*.*s", -2,-7, NULL);
    T("%*.*s", -2,-7, "");
    T("%*.*s", -2,-7, "");
    T("a%*.*sa", -2,-7, "");
    T("%*.*s", -2,-7, "ABC");
    T("%*.*s", -2,-7, "ABC");
    T("%*.*s", -2,-7, "ABC");
    T("a%*.*sa", -2,-7, "ABC");*/

    printf("|%.3d|\n",-10);
    ft_printf("|%.3d|\n",-10);
    
    printf("|%15.3d|\n",-10);
    ft_printf("|%15.3d|\n",-10);

    printf("|%.*d|\n", -5, -5);
 ft_printf("|%.*d|\n", -5, -5);
}
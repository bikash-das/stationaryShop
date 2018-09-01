/* round_off.h */

#ifndef ROUND_OFF_H_INCLUDED
#define ROUND_OFF_H_INCLUDED

extern double gta;  /*gta is grand total amount after applying discount */
int rdf;  /* rdf is round off figure of gta */
int dec; /* its value determines whether to round off or not */

void convert()
{
	rdf=gta*100;

	dec=rdf%100; /* extracting the last two digit */
	rdf/=100;   /* deleting the last two digit after decimal */
	
	rdf=(gta*100)/100;
	if(dec>=50)
	   rdf++;
}
#endif

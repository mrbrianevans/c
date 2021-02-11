struct servicePoint
{
	CUSTOMER customer; /* the customer currently being served */

};
struct servicePoints
{
	/*need an array of service points*/
	SERVICE_POINT[] points;
	int numServicePoints;
};
typedef struct servicePoints SERVICE_POINTS;

extern SERVICE_POINTS *makeServicePoints(int numServicePoints);

int getNumAvailableServicePoints();

int serveCustomer(CUSTOMER customer);




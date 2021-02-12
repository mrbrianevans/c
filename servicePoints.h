struct servicePoint
{
	CUSTOMER customer; /* the customer currently being served */

};
typedef struct servicePoint SERVICE_POINT;

struct servicePoints
{
	/*need an array of service points*/
	SERVICE_POINT[] points;
	int numServicePoints;
};
typedef struct servicePoints SERVICE_POINTS;

extern SERVICE_POINTS *makeServicePoints(int numServicePoints);
extern int getNumAvailableServicePoints();
extern int serveCustomer(CUSTOMER customer);

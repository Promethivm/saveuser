#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

struct User
{
	char firstName[80];
	char lastName[80];
	char websiteURL[80];
};

void saveUser(User u)
{
	FILE *fp;
	fp = fopen("Users.dat","ab");
	int d = fileno(fp);
	write(d, &u, sizeof u);
	fclose(fp);
}

int main(void)
{
	User jim;
	memset(&jim, 0, sizeof jim);
	strcpy(jim.firstName, "Jimmy");
	strcpy(jim.lastName, "Smith");
	strcpy(jim.websiteURL, "http//example.com/");

	saveUser(jim);
	return 0;
}

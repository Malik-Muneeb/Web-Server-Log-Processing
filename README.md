# Web-Server-Log-Processing
objective	is	to	read	a	web	server	log	file	line	by	line	and	process	it	to	identify	total	number	of	requests	and	average	
response	size	against	each	web	page.	The	input	log	file	would	be	in	the	following	format:	
10.223.157.186	- - [15/Jul/2009:14:58:59	-0700]	"GET	/	HTTP/1.1"	403	202
10.211.47.159	- - [06/Jan/2010:23:35:03	-0800]	"GET	/crm/campaigns_contacts.php?c=22&_search=false&	50&page=1	HTTP/1.1"	200	231
10.211.47.159	- - [06/Jan/2010:23:35:03	-0800]	"GET	/crm/	campaigns_contacts?c=22nd=1262849703513&rows=50	HTTP/1.1"	200	4162
10.121.241.75	- - [06/Jan/2010:23:28:59	-0800]	"GET	/robots.txt	HTTP/1.0"	404	208
10.121.241.75	- - [06/Jan/2010:23:28:59	-0800]	"GET	/	HTTP/1.0"	200 12758

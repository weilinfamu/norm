#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>//数据转换 随机数 字符集转换函数
void lession14() {
	const char str[] = "hello world!1.99\r\n\t1981-12-08\r\n\vby冯攀\r\n";
	size_t len = sizeof(str);
	for (size_t i = 0; i < len; i++) {
		std::cout << str[i] << ":";
		if (isalnum(str[i]))std::cout << "A";
		if (isalpha(str[i]))std::cout << "a";
		if (isascii(str[i]))std::cout << "B";
		if (isblank(str[i]))std::cout << "b";
		if (iscntrl(str[i]))std::cout << "C";
		if (isdigit(str[i]))std::cout << "D";
		if (isgraph(str[i]))std::cout << "G";
		if (isprint(str[i]))std::cout << "g";
		if (islower(str[i]))std::cout << "L";
		if (isupper(str[i]))std::cout << "U";
		if (isspace(str[i]))std::cout << "S";
		if (ispunct(str[i]))std::cout << "P";
		if (isxdigit(str[i]))std::cout << "H";
		std::cout << std::endl;
	}
}

void lession15()
{
	long a;
	int b;
	std::cout << "long:" << sizeof(a) << " int:" << sizeof(b) << " long long:" << sizeof(long long) << std::endl;
	std::cout << "long double:" << sizeof(long double) << std::endl;
	std::cout << atoi("123456") << std::endl;//cpu 8 16 32 64  以前i=16 l=32  现在i=32 l=64 ll=64
	std::cout << atol("234567") << std::endl;
	std::cout << atoll("1234567890123") << std::endl;//新特征，要先验证，再使用
	std::cout << atof("1.234567") << std::endl;
	std::cout << strtol("-987654321", NULL, 10) << std::endl;
	char* pEnd;
	std::cout << strtoll("-987654321000abc123456", &pEnd, 10) << std::endl;
	std::cout << "pEnd:" << pEnd << std::endl;
	std::cout << strtof("1.2345678", NULL) << std::endl;
	std::cout << strtod("1.234567890123", NULL) << std::endl;
	double d = strtod("1.234567890123", NULL);
	printf("%lf %g\r\n", strtod("1.234567890123", NULL), d);
	std::cout << d << std::endl;
	std::cout << strtold("1.234567890123456789", NULL) << std::endl;
	printf("%Lf\r\n", strtold("1.234567890123456789", NULL));
}

void lession16()
{
	int decpt, sign;
	std::cout << ecvt(0.123456789, 10, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << ecvt(0.0123456789, 10, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << ecvt(-123.456789, 10, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << ecvt(100, 4, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << "=================================================" << std::endl;
	std::cout << fcvt(0.123456789, 10, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << fcvt(0.0123456789, 10, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << fcvt(-123.456789, 10, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << fcvt(100, 3, &decpt, &sign) << std::endl;
	std::cout << "decpt:" << decpt << " sign:" << sign << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	char buffer[128] = "";
	std::cout << gcvt(0.123456789, 10, buffer) << std::endl;
	std::cout << buffer << std::endl;
	std::cout << gcvt(0.0123456789, 10, buffer) << std::endl;
	std::cout << buffer << std::endl;
	std::cout << gcvt(-123.456789, 10, buffer) << std::endl;
	std::cout << buffer << std::endl;
	std::cout << gcvt(100, 10, buffer) << std::endl;
	std::cout << buffer << std::endl;
}
#include <stdarg.h>

void test(const char* format, ...) {
	va_list ap;
	va_start(ap, format);
	vprintf(format, ap);
	char buffer[4906] = "";
	va_start(ap, format);
	vsnprintf(buffer, sizeof(buffer), format, ap);
	va_start(ap, format);
	vsprintf(buffer, format, ap);
}

void lession17() {
	printf("hello world\n");
	printf("%d %u %l %lld %f %e %g\n", 1, 2, 3, 4, 0.00001, 0.00001, 0.00001);
	printf("%s\n", "ok");
	char buffer[128] = "";
	sprintf(buffer, "%s %d %f\n", "yidaoyun", 100, 100.12345);
	std::cout << buffer << std::endl;
	snprintf(buffer, sizeof(buffer), "%s %d %f\n", "yidaoyun", 100, 100.12345);
	FILE* pFile = fopen("test.txt", "w+");
	fprintf(pFile, "%s %d %f\n", "yidaoyun", 100, 100.12345);
	fclose(pFile);
	test("%s %d %f\n", "yidaoyun", 100, 100.12345);
}

void lession19()
{
	char c;
	int d;
	float f;
	double db;
	int ret = scanf("%c%d,%f,%lf", &c, &d, &f, &db);
	printf("ret=%d %c %d %f %lf\n", ret, c, d, f, db);
}
#include <unistd.h>

void lession22()
{
	std::cout << getuid() << std::endl;
	std::cout << geteuid() << std::endl;
	std::cout << getgid() << std::endl;
	std::cout << getegid() << std::endl;
	std::cout << "setuid:" << setuid(0) << std::endl;
	std::cout << "setgid:" << setgid(0) << std::endl;
	std::cout << getuid() << std::endl;
	std::cout << geteuid() << std::endl;
	std::cout << getgid() << std::endl;
	std::cout << getegid() << std::endl;
}

void lession23()
{
	std::cout << setsid() << std::endl;//主进程的时候必然失败
}

#include <fcntl.h>
#include <sys/file.h>
#include <errno.h>//errno
#include <string.h>//strerror

void lession30()
{
	//int fd = open("/home/feng/test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	int fd = open("/home/feng/test.txt", O_RDWR | O_CREAT, 0755);//权限是八进制的
	if (fd >= 0) {//文件锁其实是一个建议性的锁 
		//printf("write:%d\n", write(fd, "hello", 5));
		printf("flock:%d\n", flock(fd, LOCK_EX));
		printf("write:%d\n", write(fd, "hello", 5));
		sleep(6);
		flock(fd, LOCK_UN);
		close(fd);
	}
	else {
		std::cout << strerror(errno) << std::endl;
	}

}

void lession32()
{
	pid_t pid = fork();
	if (pid > 0) {
		//sleep(1);
		std::cout << "hello,here is parent!" << pid << std::endl;
	}
	else {
		sleep(3);
		execl("/bin/ls", "ls", "-l", NULL);//argv的第一个参数，一定要是命令的自身
	}
}
#include <assert.h>
void lession33_exit() {
	printf("%s\n", __FUNCTION__);
}
void lession33_on_exit(int status, void* p) {
	printf("%s p=%p status=%d\n", __FUNCTION__, p, status);
}
void lession33()
{
	pid_t pid = fork();
	if (pid > 0) {//父进程
		atexit(lession33_exit);
		//sleep(1);
		std::cout << "hello,here is parent!" << pid << std::endl;
		abort();//不会触发atexit或者on_exit
		exit(0);
	}
	else {//子进程
		on_exit(lession33_on_exit, (void*)1);
		sleep(3);
		assert(0);//不会触发atexit或者on_exit
		_exit(-1);//不会触发atexit或者on_exit
		//execl("/bin/ls", "ls", NULL);//argv的第一个参数，一定要是命令的自身
		//assert(0);
		//execl("/bin/ls", "ls", "-l", NULL);//argv的第一个参数，一定要是命令的自身

	}
}

#include <setjmp.h>
#include <signal.h>
jmp_buf jmpbuf;
void test002() {
	//TODO:...
	longjmp(jmpbuf, 1);
}
void test003()
{
	longjmp(jmpbuf, 2);
}
void test001() {
	//TODO:...
	test002();
}
void signal_deal(int sig)
{
	if (sig == SIGSEGV) {
		longjmp(jmpbuf, SIGSEGV);
	}
}
void lession34()
{
	signal(SIGSEGV, signal_deal);//异常捕获
	//struct sigaction act, actold;
	//act.sa_restorer
	//sigaction(SIGSEGV, &act, &actold);

	int ret = setjmp(jmpbuf);
	if (ret == 0) {//实际上是C语言当中，处理异常的一种机制
		//test001();
		*(int*)(NULL) = 0;
	}
	else if (ret == 1) {//错误1的处理和恢复
		printf("error 1\n");
	}
	else if (ret == 2) {//错误2的处理和恢复
		printf("error 2\n");
	}
	else if (ret == SIGSEGV) {//错误2的处理和恢复
		printf("error SIGSEGV\n");
	}
}
#include <sys/resource.h>
void lession35()
{
	std::cout << "getpgid:" << getpgid(getpid()) << std::endl;
	std::cout << "getpid:" << getpid() << std::endl;
	std::cout << "getpgrp:" << getpgrp() << std::endl;
	std::cout << "getppid:" << getppid() << std::endl;
	std::cout << "getpriority:" << getpriority(PRIO_PROCESS, getpid()) << std::endl;
	sleep(15);
}

void lession36()
{
	std::cout << "*getpgrp:" << getpgrp() << std::endl;
	std::cout << "setpgid:" << setpgid(getpid(), 1) << std::endl;
	std::cout << "*getpgrp:" << getpgrp() << std::endl;
	std::cout << "setpgrp(void):" << setpgrp() << std::endl;
	std::cout << "*getpgrp:" << getpgrp() << std::endl;
	std::cout << "$getpriority:" << getpriority(PRIO_PROCESS, getpid()) << std::endl;
	std::cout << "nice:" << nice(3) << std::endl;
	std::cout << "$getpriority:" << getpriority(PRIO_PROCESS, getpid()) << std::endl;
	std::cout << "setpriority:" << setpriority(PRIO_PROCESS, getpid(), 1) << std::endl;
	std::cout << "$getpriority:" << getpriority(PRIO_PROCESS, getpid()) << std::endl;

}
void lession37()
{
	int ret = system("ls -l");
	printf("system return:%d\n", ret);
	ret = system("mkdir test");
	printf("system return:%d\n", ret);
	char buffer[256] = "";
	snprintf(buffer, sizeof(buffer), "echo \"%s\">test/test.txt", __FUNCTION__);
	printf("%s\n", buffer);
	ret = system(buffer);
	printf("system return:%d\n", ret);
}

void lession38()
{
	FILE* pFile = fopen("./test.txt", "w+");
	if (pFile != NULL) {
		//TODO: 读写和处理
		fclose(pFile);
	}
}

void lession39()
{
	FILE* pFile = freopen("./test.txt", "w+", stdout);
	if (pFile != NULL) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		fclose(pFile);
	}
	else {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	}
}


//char buffer[65536] = "";//<512M  <2G
void lession40()
{
	FILE* pFile = fopen("./test.txt", "r");
	if (pFile != NULL) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		//char buffer[4096] = "";//栈上的数据 不要太大（64k==》32k以内）
		char* buffer = new char[1024 * 1024 * 10];//单次内存分配，不要超过2G  64位系统不要超过8G
		memset(buffer, 0, 1024 * 1024 * 10);
		size_t ret = fread(buffer, 1, 1024, pFile);
		printf("%s(%d):%s read count %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
		printf("%s(%d):%s <%s>\n", __FILE__, __LINE__, __FUNCTION__, buffer);
		fclose(pFile);
		//fread(buffer, 2, 1000);
	}
	else {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	}
}

void lession41()
{
	FILE* pFile = fopen("./test.txt", "r");
	if (pFile != NULL) {
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		char buffer[1024] = "";
		printf("%s(%d):%s [%s]\n", __FILE__, __LINE__, __FUNCTION__, fgets(buffer, sizeof(buffer), pFile));
		printf("%s(%d):%s [%d]\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		fclose(pFile);
	}
}

void lession42()
{
	FILE* pFile = fopen("./test.txt", "r+");
	if (pFile != NULL) {
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		fputc('/', pFile);
		char buffer[1024] = "";
		printf("%s(%d):%s [%s]\n", __FILE__, __LINE__, __FUNCTION__, fgets(buffer, sizeof(buffer), pFile));
		printf("%s(%d):%s [%d]\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		fputs(__FUNCTION__, pFile);
		fclose(pFile);
	}
}

struct Test {
	int id;
	char name[64];
	int age;
};

void lession43()
{
	FILE* pFile = fopen("./test1.txt", "w+");
	if (pFile) {
		struct Test data = {
			1000,"tiger",28
		};
		size_t ret = fwrite(&data, 1, sizeof(Test), pFile);
		printf("%s(%d):%s ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
		fclose(pFile);
	}
	pFile = fopen("./test1.txt", "rb");
	if (pFile) {
		struct Test read;
		size_t ret = fread(&read, 1, sizeof(Test), pFile);
		printf("%s(%d):%s ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
		fclose(pFile);
		printf("%s(%d):%s ret = %d\n", __FILE__, __LINE__, __FUNCTION__, read.id);
		printf("%s(%d):%s ret = [%s]\n", __FILE__, __LINE__, __FUNCTION__, read.name);
		printf("%s(%d):%s ret = %d\n", __FILE__, __LINE__, __FUNCTION__, read.age);
	}
}

void lession44()
{
	FILE* pFile = fopen("./test.txt", "r");
	if (pFile) {
		printf("%s(%d):%s ftell = %d\n", __FILE__, __LINE__, __FUNCTION__, ftell(pFile));
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		printf("%s(%d):%s ftell = %d\n", __FILE__, __LINE__, __FUNCTION__, ftell(pFile));
		fseek(pFile, 0, SEEK_SET);//SEEK_CUR, SEEK_END;
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		fseek(pFile, -1, SEEK_CUR);
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		fseek(pFile, -66, SEEK_END);
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		printf("%s(%d):%s ftell = %d\n", __FILE__, __LINE__, __FUNCTION__, ftell(pFile));
		fpos_t pos;
		fgetpos(pFile, &pos);//64位文件读写、
		pos.__pos -= 1;
		fsetpos(pFile, &pos);
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		printf("%s(%d):%s ftell = %d\n", __FILE__, __LINE__, __FUNCTION__, ftell(pFile));
		fclose(pFile);
	}
}

void lession45()
{
	FILE* pFile = fopen("./test.txt", "r+");
	if (pFile) {
		char buffer[1024] = "";
		while (!feof(pFile)) {
			printf("%s(%d):%s feof = %d\n", __FILE__, __LINE__, __FUNCTION__, feof(pFile));
			bzero(buffer, sizeof(buffer));
			printf("%s(%d):%s [%s]\n", __FILE__, __LINE__, __FUNCTION__, fgets(buffer, sizeof(buffer), pFile));
		}
		printf("%s(%d):%s feof = %d\n", __FILE__, __LINE__, __FUNCTION__, feof(pFile));
		printf("%s(%d):%s ferror = %d\n", __FILE__, __LINE__, __FUNCTION__, ferror(pFile));
		fputc('a', pFile);
		printf("%s(%d):%s ferror = %d\n", __FILE__, __LINE__, __FUNCTION__, ferror(pFile));
		clearerr(pFile);
		fseek(pFile, 100, SEEK_SET);
		printf("%s(%d):%s ferror = %d\n", __FILE__, __LINE__, __FUNCTION__, ferror(pFile));
		printf("%s(%d):%s ftell = %d\n", __FILE__, __LINE__, __FUNCTION__, ftell(pFile));
		fputc('a', pFile);
		fseek(pFile, -1, SEEK_CUR);
		printf("%s(%d):%s %c\n", __FILE__, __LINE__, __FUNCTION__, fgetc(pFile));
		fclose(pFile);
	}
}
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
void lession46()
{
	int ret = 0;
	//ret = rmdir(__FUNCTION__);
	//printf("%s(%d):%s ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
	ret = mkdir(__FUNCTION__, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH);
	printf("%s(%d):%s ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
	system("echo \"test\" > lession46/test.txt");
	ret = rmdir(__FUNCTION__);
	printf("%s(%d):%s rmdir ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
	ret = remove("lession46/test.txt");
	ret = remove(__FUNCTION__);
	printf("%s(%d):%s remove ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
	//ret = rmdir(__FUNCTION__);
	//printf("%s(%d):%s rmdir ret = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
}

void lession47()
{
	int ret = 0;
	uid_t uid = getuid();
	gid_t gid = getgid();
	ret = chown("./test", uid, gid);
	printf("%s(%d):%s chown = %d uid = %d gid = %d\n", __FILE__, __LINE__, __FUNCTION__, ret, getuid(), getgid());
	setuid(0);
	ret = chown("./test", uid, gid);
	printf("%s(%d):%s chown = %d uid = %d gid = %d\n", __FILE__, __LINE__, __FUNCTION__, ret, getuid(), getgid());
	ret = chmod("test.txt", 0600 | S_IRGRP | S_IROTH);
	printf("%s(%d):%s chmod = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
	ret = unlink("test.txt");
	printf("%s(%d):%s unlink = %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
}
#include <sys/types.h>
#include <dirent.h>

void dump_files(const char* root)
{
	printf("***************************************************************\n");
	DIR* proot = opendir(root);
	if (proot == NULL) {
		printf("%s(%d):%s ~ is not exist!\n", __FILE__, __LINE__, __FUNCTION__);
		return;
	}
	dirent* pCur = NULL;
	do {
		pCur = readdir(proot);
		if (pCur != NULL) {
			if (strcmp(pCur->d_name, ".") == 0 || strcmp(pCur->d_name, "..") == 0)
				continue;
			if (pCur->d_type & DT_DIR) {
				char buffer[512] = "";
				snprintf(buffer, sizeof(buffer), "%s/%s", root, pCur->d_name);
				printf("%s(%d):%s %s\n", __FILE__, __LINE__, __FUNCTION__, buffer);
				dump_files(buffer);
			}
		}
	} while (pCur != NULL);
	closedir(proot);
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

void lession48()
{
	dump_files("/home/feng/projects");
	//DIR* proot = opendir("/home/feng");
	//if (proot == NULL) {
	//	printf("%s(%d):%s ~ is not exist!\n", __FILE__, __LINE__, __FUNCTION__);
	//	return;
	//}
	//dirent* pCur = NULL;
	//do {
	//	pCur = readdir(proot);
	//	if (pCur != NULL) {
	//		if (strcmp(pCur->d_name, ".") == 0 || strcmp(pCur->d_name, "..") == 0)
	//			continue;
	//		if (pCur->d_type & DT_DIR) {
	//			printf("%s(%d):%s %s\n", __FILE__, __LINE__, __FUNCTION__, pCur->d_name);
	//		}
	//	}
	//} while (pCur != NULL);
	//closedir(proot);
}
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
void lession57()
{
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock != -1) {
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr("192.168.0.1");
		addr.sin_port = htons(9527);
		int ret = bind(sock, (struct sockaddr*)&addr, sizeof(addr));
		if (ret != 0) {
			//报错在此
		}
	}
}

void lession60()
{
	int server, client;
	struct sockaddr_in seraddr, cliaddr;
	socklen_t cliaddrlen;
	const char* message = "hello world!\n";
	server = socket(PF_INET, SOCK_STREAM, 0);//TCP
	if (server < 0) {
		std::cout << "create socket failed!" << std::endl;
		return;
	}
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	seraddr.sin_port = htons(9527);
	int ret = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	if (ret == -1) {
		std::cout << "bind failed!" << std::endl;
		close(server);
		return;
	}
	ret = listen(server, 3);
	if (ret == -1) {
		std::cout << "listen failed!" << std::endl;
		close(server);
		return;
	}
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	client = accept(server, (struct sockaddr*)&cliaddr, &cliaddrlen);
	if (client == -1) {
		std::cout << "accept failed!" << std::endl;
		close(server);
		return;
	}
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	ssize_t len = write(client, message, strlen(message));
	if (len != (ssize_t)strlen(message)) {
		std::cout << "write failed!" << std::endl;
		close(server);
		return;
	}
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	close(client);//可以不执行的
	close(server);//因为服务端关闭的时候，客户端会自动关闭
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
}
#include <sys/wait.h>
void lession62()
{
	pid_t pid = fork();
	if (pid == 0) {
		//开启客户端
		sleep(1);
		int client = socket(PF_INET, SOCK_STREAM, 0);
		struct sockaddr_in servaddr;
		memset(&servaddr, 0, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servaddr.sin_port = htons(9527);
		int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
		if (ret == 0) {
			printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
			char buffer[256] = "";
			read(client, buffer, sizeof(buffer));
			std::cout << buffer;
		}
		else {
			printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
		}
		close(client);
		std::cout << "client done!" << std::endl;
	}
	else if (pid > 0) {
		lession60();
		int status = 0;
		wait(&status);
	}
	else {
		std::cout << "fork failed!" << pid << std::endl;
	}
}
void run_client()
{
	int client = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9527);
	int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
	if (ret == 0) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		char buffer[256] = "hello ,here is client!\n";
		write(client, buffer, strlen(buffer));
		memset(buffer, 0, sizeof(buffer));
		read(client, buffer, sizeof(buffer));
		std::cout << buffer;
	}
	else {
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, ret);
	}
	close(client);
	std::cout << "client done!" << std::endl;
}

void lession63_() {
	int server, client;
	struct sockaddr_in seraddr, cliaddr;
	socklen_t cliaddrlen;
	//const char* message = "hello world!\n";
	server = socket(PF_INET, SOCK_STREAM, 0);//TCP
	if (server < 0) {
		std::cout << "create socket failed!" << std::endl;
		return;
	}
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	seraddr.sin_port = htons(9527);
	int ret = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	if (ret == -1) {
		std::cout << "bind failed!" << std::endl;
		close(server);
		return;
	}
	ret = listen(server, 3);
	if (ret == -1) {
		std::cout << "listen failed!" << std::endl;
		close(server);
		return;
	}
	char buffer[1024];
	while (1) {
		memset(buffer, 0, sizeof(buffer));
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		client = accept(server, (struct sockaddr*)&cliaddr, &cliaddrlen);
		if (client == -1) {
			std::cout << "accept failed!" << std::endl;
			close(server);
			return;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		read(client, buffer, sizeof(buffer));
		ssize_t len = write(client, buffer, strlen(buffer));
		if (len != (ssize_t)strlen(buffer)) {
			std::cout << "write failed!" << std::endl;
			close(server);
			return;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		close(client);//可以不执行的
	}
	close(server);//因为服务端关闭的时候，客户端会自动关闭
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
}
void lession63()
{
	pid_t pid = fork();
	if (pid == 0) {
		//开启客户端
		sleep(1);
		run_client();
		run_client();
	}
	else if (pid > 0) {
		lession63_();
		int status = 0;
		wait(&status);
	}
	else {
		std::cout << "fork failed!" << pid << std::endl;
	}
}

void run_client64()
{
	int client = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9527);
	int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
	while (ret == 0) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		char buffer[256] = "";
		fputs("Input message(Q to quit):", stdout);
		fgets(buffer, sizeof(buffer), stdin);
		if ((strcmp(buffer, "q\n") == 0) || (strcmp(buffer, "Q\n") == 0)) {
			break;
		}
		write(client, buffer, strlen(buffer));
		memset(buffer, 0, sizeof(buffer));
		read(client, buffer, sizeof(buffer));
		std::cout << buffer;
	}
	close(client);
	std::cout << "client done!" << std::endl;
}
void server64()
{
	int server, client;
	struct sockaddr_in seraddr, cliaddr;
	socklen_t cliaddrlen;
	//const char* message = "hello world!\n";
	server = socket(PF_INET, SOCK_STREAM, 0);//TCP
	if (server < 0) {
		std::cout << "create socket failed!" << std::endl;
		return;
	}
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	seraddr.sin_port = htons(9527);
	int ret = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	if (ret == -1) {
		std::cout << "bind failed!" << std::endl;
		close(server);
		return;
	}
	ret = listen(server, 3);
	if (ret == -1) {
		std::cout << "listen failed!" << std::endl;
		close(server);
		return;
	}
	char buffer[1024];
	for (int i = 0; i < 2; i++) {
		memset(buffer, 0, sizeof(buffer));
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		client = accept(server, (struct sockaddr*)&cliaddr, &cliaddrlen);
		if (client == -1) {
			std::cout << "accept failed!" << std::endl;
			close(server);
			return;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		//ssize_t len = read(client, buffer, sizeof(buffer));
		ssize_t len = 0;
		while ((len = read(client, buffer, sizeof(buffer))) > 0) {
			len = write(client, buffer, len);
			if (len != (ssize_t)strlen(buffer)) {
				std::cout << "write failed!len:" << len << " buffer:" << buffer << std::endl;
				close(server);
				return;
			}
			memset(buffer, 0, len);
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		close(client);//可以不执行的
	}
	close(server);//因为服务端关闭的时候，客户端会自动关闭
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
}

void lession64()
{
	pid_t pid = fork();
	if (pid == 0) {
		//开启服务器
		server64();
	}
	else if (pid > 0) {
		for (int i = 0; i < 2; i++)
			run_client64();
		int status = 0;
		wait(&status);
	}
	else {
		std::cout << "fork failed!" << pid << std::endl;
	}
}

void run_client65()
{
	int client = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9527);
	int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
	while (ret == 0) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		char buffer[256] = "";
		fputs("Input message(Q to quit):", stdout);
		fgets(buffer, sizeof(buffer), stdin);
		if ((strcmp(buffer, "q\n") == 0) || (strcmp(buffer, "Q\n") == 0)) {
			break;
		}
		size_t len = strlen(buffer);
		size_t send_len = 0;
		while (send_len < len) {
			ssize_t ret = write(client, buffer + send_len, len - send_len);
			if (ret <= 0) {
				fputs("write failed!\n", stdout);
				close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			send_len += (size_t)ret;
		}
		memset(buffer, 0, sizeof(buffer));
		size_t read_len = 0;
		while (read_len < len) {
			ssize_t ret = read(client, buffer + read_len, len - read_len);
			if (ret <= 0) {
				fputs("read failed!\n", stdout);
				close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			read_len += (size_t)ret;
		}
		std::cout << "from server:" << buffer;
	}
	close(client);
	std::cout << "client done!" << std::endl;
}
void server65()
{
	int server, client;
	struct sockaddr_in seraddr, cliaddr;
	socklen_t cliaddrlen;
	//const char* message = "hello world!\n";
	server = socket(PF_INET, SOCK_STREAM, 0);//TCP
	if (server < 0) {
		std::cout << "create socket failed!" << std::endl;
		return;
	}
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	seraddr.sin_port = htons(9527);
	int ret = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	if (ret == -1) {
		std::cout << "bind failed!" << std::endl;
		close(server);
		return;
	}
	ret = listen(server, 3);
	if (ret == -1) {
		std::cout << "listen failed!" << std::endl;
		close(server);
		return;
	}
	char buffer[1024];
	for (int i = 0; i < 2; i++) {
		memset(buffer, 0, sizeof(buffer));
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		client = accept(server, (struct sockaddr*)&cliaddr, &cliaddrlen);
		if (client == -1) {
			std::cout << "accept failed!" << std::endl;
			close(server);
			return;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		//ssize_t len = read(client, buffer, sizeof(buffer));
		ssize_t len = 0;
		while ((len = read(client, buffer, sizeof(buffer))) > 0) {
			len = write(client, buffer, len);
			if (len != (ssize_t)strlen(buffer)) {
				std::cout << "write failed!len:" << len << " buffer:" << buffer << std::endl;
				close(server);
				return;
			}
			memset(buffer, 0, len);
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		close(client);//可以不执行的
	}
	close(server);//因为服务端关闭的时候，客户端会自动关闭
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
}

void lession65()
{
	pid_t pid = fork();
	if (pid == 0) {
		//开启服务器
		server65();
	}
	else if (pid > 0) {
		for (int i = 0; i < 2; i++)
			run_client65();
		int status = 0;
		wait(&status);
	}
	else {
		std::cout << "fork failed!" << pid << std::endl;
	}
}

void run_client66()
{
	int client = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9527);
	int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
	char buffer[1024] = "";
	while (ret == 0) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);

		fputs("Operand count: ", stdout);
		int opnd_cnt = 0;
		scanf("%d", &opnd_cnt);
		if (opnd_cnt <= 1 && opnd_cnt >= 256) {
			fputs("opnd_cnt error,too small or too big!\n", stdout);
			close(client);
			std::cout << "client done!" << opnd_cnt << std::endl;
			return;
		}
		buffer[0] = (char)opnd_cnt;//服务器此处要解释为无符号
		for (int i = 0; i < opnd_cnt; i++)
			scanf("%d", buffer + 1 + i * 4);
		fgetc(stdin);
		fputs("Operator:", stdout);
		buffer[1 + opnd_cnt * 4] = (char)fgetc(stdin);

		size_t len = opnd_cnt * 4 + 2;
		size_t send_len = 0;
		while (send_len < len) {
			ssize_t ret = write(client, buffer + send_len, len - send_len);
			if (ret <= 0) {
				fputs("write failed!\n", stdout);
				close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			send_len += (size_t)ret;
		}
		memset(buffer, 0, sizeof(buffer));
		size_t read_len = 0;
		while (read_len < 4) {
			ssize_t ret = read(client, buffer + read_len, len - read_len);
			if (ret <= 0) {
				fputs("read failed!\n", stdout);
				close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			read_len += (size_t)ret;
			printf("from server count:%d\n", ret);
		}
		printf("from server:%d\n", *(int*)buffer);
	}
	close(client);
	std::cout << "client done!" << std::endl;
}

int calculate(int count, int oprand[], char op)
{
	int result = 0;
	switch (op) {
	case '+':
		for (int i = 0; i < count; i++) {
			result += oprand[i];
		}
		break;
	case '-':
		for (int i = 0; i < count; i++) {
			result -= oprand[i];
		}
		break;
	case '*':
		result = 1;
		for (int i = 0; i < count; i++) {
			result *= oprand[i];
		}
		break;
	default:
		break;
	}
	return result;
}

void server66()
{
	int server, client;
	struct sockaddr_in seraddr, cliaddr;
	socklen_t cliaddrlen;
	//const char* message = "hello world!\n";
	server = socket(PF_INET, SOCK_STREAM, 0);//TCP
	if (server < 0) {
		std::cout << "create socket failed!" << std::endl;
		return;
	}
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_addr.s_addr = inet_addr("0.0.0.0");
	seraddr.sin_port = htons(9527);
	int ret = bind(server, (struct sockaddr*)&seraddr, sizeof(seraddr));
	if (ret == -1) {
		std::cout << "bind failed!" << std::endl;
		close(server);
		return;
	}
	ret = listen(server, 3);
	if (ret == -1) {
		std::cout << "listen failed!" << std::endl;
		close(server);
		return;
	}
	char buffer[1024];
	for (int i = 0; i < 2; i++) {
		memset(buffer, 0, sizeof(buffer));
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		client = accept(server, (struct sockaddr*)&cliaddr, &cliaddrlen);
		if (client == -1) {
			std::cout << "accept failed!" << std::endl;
			close(server);
			return;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		//ssize_t len = read(client, buffer, sizeof(buffer));
		ssize_t len = 0;
		len = read(client, buffer, 1);
		int result = 0;
		if (len > 0) {
			for (unsigned i = 0; i < ((unsigned)buffer[0] & 0xFF); i++)
				read(client, buffer + 1 + i * 4, 4);
			read(client, buffer + 1 + ((unsigned)buffer[0] & 0xFF) * 4, 1);
			result = calculate(((int)buffer[0] & 0xFF), (int*)(buffer + 1), buffer[1 + ((unsigned)buffer[0] & 0xFF) * 4]);
			write(client, &result, 4);
			std::cout << "result:" << result << std::endl;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		read(client, buffer, 1);
		close(client);//可以不执行的
	}
	close(server);//因为服务端关闭的时候，客户端会自动关闭
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
}

void lession66()
{
	pid_t pid = fork();
	if (pid == 0) {
		//开启服务器
		server66();
	}
	else if (pid > 0) {
		for (int i = 0; i < 2; i++)
			run_client66();
		int status = 0;
		wait(&status);
	}
	else {
		std::cout << "fork failed!" << pid << std::endl;
	}
}

void handle_error(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(-1);
}

int lession73(int argc, char* argv[])
{
	int ser_sock = -1;
	char message[512] = "";
	struct sockaddr_in servaddr, clientaddr;
	socklen_t clientlen = 0;

	if (argc != 2) {
		printf("usage:% <port>\n", argv[0]);
		handle_error("argement is error:");
	}

	ser_sock = socket(PF_INET, SOCK_DGRAM, 0);//UDP
	if (ser_sock == -1) {
		handle_error("create socket failed:");
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//0.0.0.0
	servaddr.sin_port = htons((short)atoi(argv[1]));

	if (bind(ser_sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
		handle_error("bind failed:");
	}

	for (int i = 0; i < 10; i++) {
		clientlen = sizeof(clientaddr);
		ssize_t len = recvfrom(ser_sock, message, sizeof(message), 0, (struct sockaddr*)&clientaddr, &clientlen);
		sendto(ser_sock, message, len, 0, (struct sockaddr*)&clientaddr, clientlen);
	}

	close(ser_sock);
	return 0;
}

int lession74(int argc, char* argv[])
{
	//变量声明
	int client_sock;
	struct sockaddr_in serv_addr;
	socklen_t serv_len = sizeof(serv_addr);
	char message[512] = "";

	if (argc != 3) {
		printf("usage:%s ip port\n", argv[0]);
		handle_error("argement error!");
	}

	client_sock = socket(PF_INET, SOCK_DGRAM, 0);
	if (client_sock == -1) {
		handle_error("socket create failed!");
	}

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons((short)atoi(argv[2]));

	while (1) {
		printf("input message(q to Quit):");
		scanf("%s", message);
		if ((strcmp(message, "q") == 0) || (strcmp(message, "Q") == 0)) {
			printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
			break;
		}
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		ssize_t len = sendto(client_sock, message, strlen(message), 0, (sockaddr*)&serv_addr, serv_len);
		memset(message, 0, len);
		recvfrom(client_sock, message, sizeof(message), 0, (sockaddr*)&serv_addr, &serv_len);
		printf("recv:%s\n", message);
	}

	close(client_sock);
	return 0;
}

void lession75(char* argv0)
{
	if (fork() > 0) {//主进程
		int argc = 3;
		char* argv[] = {
			argv0,
			(char*)"127.0.0.1",//const char*
			(char*)"9999"
		};
		lession74(argc, argv); //客户端
		int status = 0;
		wait(&status);
	}
	else {//子进程
		int argc = 2;
		char* argv[] = {
			argv0,
			(char*)"9999"
		};
		lession73(argc, argv);//服务器
	}
}

void lession76()
{
	int tcp_sock, udp_sock;
	int optval = 0;
	socklen_t len = sizeof(optval);

	tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
	udp_sock = socket(PF_INET, SOCK_DGRAM, 0);

	printf("SOCK_STREAM:%d\n", SOCK_STREAM);
	printf("SOCK_DGRAM:%d\n", SOCK_DGRAM);

	getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void*)&optval, &len);
	printf("tcp_sock type is :%d\n", optval);
	optval = 0;
	getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void*)&optval, &len);
	printf("udp_sock type is :%d\n", optval);
	optval = 0;
	getsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void*)&optval, &len);
	printf("tcp_sock send buffer size is :%d\n", optval);
	optval = 1024 * 1024;
	setsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void*)&optval, len);
	getsockopt(tcp_sock, SOL_SOCKET, SO_SNDBUF, (void*)&optval, &len);
	printf("*tcp_sock send buffer size is :%d\n", optval);

	close(tcp_sock);
	close(udp_sock);
}

void server78()
{
	printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	int sock, client, optval = 0;
	struct sockaddr_in addr, cli;
	socklen_t addrlen = sizeof(addr);
	char message[256] = "";

	sock = socket(PF_INET, SOCK_STREAM, 0);
	getsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, &addrlen);
	printf("SO_REUSEADDR = %d\n", optval);
	optval = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, addrlen);
	getsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, &addrlen);
	printf("SO_REUSEADDR = %d\n", optval);

	memset(&addr, 0, addrlen);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(9527);
	addrlen = sizeof(addr);
	if (bind(sock, (struct sockaddr*)&addr, addrlen) == -1) {
		handle_error("bind failed");
	}

	listen(sock, 3);
	client = accept(sock, (struct sockaddr*)&cli, &addrlen);
	read(client, message, sizeof(message));
	close(client);
	close(sock);
	return;
}

void client78()
{
	int client = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9527);
	int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
	while (ret == 0) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		char buffer[256] = "";
		fputs("Input message(Q to quit):", stdout);
		fgets(buffer, sizeof(buffer), stdin);
		if ((strcmp(buffer, "q\n") == 0) || (strcmp(buffer, "Q\n") == 0)) {
			break;
		}
		size_t len = strlen(buffer);
		size_t send_len = 0;
		while (send_len < len) {
			ssize_t ret = write(client, buffer + send_len, len - send_len);
			if (ret <= 0) {
				fputs("write failed!\n", stdout);
				//close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			send_len += (size_t)ret;
		}
		memset(buffer, 0, sizeof(buffer));
		size_t read_len = 0;
		while (read_len < len) {
			ssize_t ret = read(client, buffer + read_len, len - read_len);
			if (ret <= 0) {
				fputs("read failed!\n", stdout);
				close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			read_len += (size_t)ret;
		}
		std::cout << "from server:" << buffer;
	}
	//close(client);
	std::cout << "client done!" << std::endl;
}

void lession78(char* option) {
	if (strcmp(option, "1") == 0) {
		server78();
		server78();
		server78();
		server78();
	}
	else {
		client78();
	}
}

void lession82()
{
	pid_t pid = fork();
	if (pid > 0) {
		sleep(30);
		int status;
		waitpid(pid, &status, 0);
	}
	else {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		exit(-1);
	}
}
#include <signal.h>
#include <sys/types.h>

void signal_func(int sig)
{
	switch (sig)
	{
	case SIGALRM:
		printf("tid %d pid %d\n", pthread_self(), getpid());
		alarm(2);
		break;
	case SIGINT:
		printf("Ctrl + C press...\n");
		exit(0);
		break;
	}
}
void lession83()
{
	printf("====tid %d pid %d\n", pthread_self(), getpid());
	signal(SIGALRM, signal_func);
	signal(SIGINT, signal_func);
	alarm(1);
	while (true) {
		printf("====tid %d pid %d\n", pthread_self(), getpid());
		sleep(3);
	}
}

void client85()
{
	int client = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(9527);
	int ret = connect(client, (struct sockaddr*)&servaddr, sizeof(servaddr));
	while (ret == 0) {
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
		char buffer[256] = "hello world";
		//fputs("Input message(Q to quit):", stdout);
		//fgets(buffer, sizeof(buffer), stdin);
		//if ((strcmp(buffer, "q\n") == 0) || (strcmp(buffer, "Q\n") == 0)) {
			//break;
		//}
		size_t len = strlen(buffer);
		size_t send_len = 0;
		while (send_len < len) {
			ssize_t ret = write(client, buffer + send_len, len - send_len);
			if (ret <= 0) {
				fputs("write failed!\n", stdout);
				//close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			send_len += (size_t)ret;
		}
		memset(buffer, 0, sizeof(buffer));
		size_t read_len = 0;
		while (read_len < len) {
			ssize_t ret = read(client, buffer + read_len, len - read_len);
			if (ret <= 0) {
				fputs("read failed!\n", stdout);
				close(client);
				std::cout << "client done!" << std::endl;
				return;
			}
			read_len += (size_t)ret;
		}
		std::cout << "from server:" << buffer;
		sleep(2);
		break;
	}
	close(client);
	std::cout << "client done!" << std::endl;
}


#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>

void hand_childProc(int sig)
{
	pid_t pid;
	int status = 0;
	pid = waitpid(-1, &status, WNOHANG);
	printf("%s(%d):%s removed sub proc:%d\r\n", __FILE__, __LINE__, __FUNCTION__, pid);
}

void server85()
{
	int serv_sock;
	struct sigaction act;
	act.sa_flags = 0;
	act.sa_handler = hand_childProc;
	sigaction(SIGCHLD, &act, 0);
	struct sockaddr_in serv_adr, client_adr;
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(9527);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (bind(serv_sock, (sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
		handle_error("bind() failed!");
	}
	if (listen(serv_sock, 5) == -1) {
		handle_error("listen() failed!");
	}
	int count = 0;
	while (true) {
		socklen_t size = sizeof(client_adr);
		int client = accept(serv_sock, (sockaddr*)&client_adr, &size);
		printf("%s(%d):%s client is connected!\n", __FILE__, __LINE__, __FUNCTION__);
		if (client >= 0) {
			count++;
			pid_t pid = fork();
			if (pid == 0) {
				close(serv_sock);
				char buffer[2048] = "";
				ssize_t length = 0;
				while ((length = read(client, buffer, sizeof(buffer))) > 0) {
					write(client, buffer, length);
				}
				close(client);
				printf("%s(%d):%s client is closed!\n", __FILE__, __LINE__, __FUNCTION__);
				return;
			}
			if (pid < 0) {
				close(client);
				printf("%s(%d):%s fork() is failed!\n", __FILE__, __LINE__, __FUNCTION__);
				break;
			}
			close(client);
		}
		if (count >= 5)break;
	}
	printf("%s(%d):%s server is over!\n", __FILE__, __LINE__, __FUNCTION__);
	close(serv_sock);
	return;
}

void lession85()
{
	pid_t pid = fork();
	if (pid == 0) {//子进程
		//启动服务器
		server85();
	}
	else if (pid > 0) {//主进程
		//启动客户端
		printf("%s(%d):%s wait server invoking!\n", __FILE__, __LINE__, __FUNCTION__);
		sleep(1);
		for (int i = 0; i < 5; i++) {
			pid = fork();
			if (pid > 0) {
				continue;
			}
			else {//子进程
				//启动客户端
				client85();
				break;
			}
		}

	}

}

void singlePipe()
{
	int fds[2] = { -1,-1 };
	char str[64] = "send by sub process!!\n";
	char buf[128] = "";
	pipe(fds);//匿名管道
	pid_t pid = fork();
	if (pid == 0) {
		write(fds[1], str, sizeof(str));
	}
	else {
		read(fds[0], buf, sizeof(buf));
		printf("%s(%d):%s server:%s\n", __FILE__, __LINE__, __FUNCTION__, buf);
	}
}

void lession87()
{
	int s2c[2], c2s[2];
	pipe(s2c);
	pipe(c2s);
	pid_t pid = fork();
	if (pid == 0) {
		char buffer[256] = "";
		write(c2s[1], "hello,i am subprocess!\n", 23);
		read(s2c[0], buffer, sizeof(buffer));
		printf("%s(%d):%s client:%s\n", __FILE__, __LINE__, __FUNCTION__, buffer);
	}
	else {
		char buffer[256] = "";
		read(c2s[0], buffer, sizeof(buffer));
		printf("%s(%d):%s server:%s\n", __FILE__, __LINE__, __FUNCTION__, buffer);
		write(s2c[1], "hello,i am mainprocess\n", 23);
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, getpid());
	}
	printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, getpid());
}

void lession88()
{
	mkfifo("./a.fifo", 0666);//命名管道
	pid_t pid = fork();
	if (pid == 0) {
		int fd = open("./a.fifo", O_RDONLY);
		char buffer[128] = "";
		ssize_t len = read(fd, buffer, sizeof(buffer));
		printf("%s(%d):%s server:%s\n", __FILE__, __LINE__, __FUNCTION__, buffer);
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, len);
		close(fd);
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	}
	else {
		int fd = open("./a.fifo", O_WRONLY);
		write(fd, "hello world", 12);
		close(fd);
		printf("%s(%d):%s\n", __FILE__, __LINE__, __FUNCTION__);
	}
}

#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct {
	int signal;
	int id;
	char name[128];
	int age;
	bool sex;
}STUDENT, * PSTUDENT;


void lession90()
{
	pid_t pid = fork();
	if (pid > 0) {//父进程
		int shm_id = shmget(ftok(".", 1), sizeof(STUDENT), IPC_CREAT | 0666);
		if (shm_id == -1) {
			printf("%s(%d):%s create share memeory failed!\n", __FILE__, __LINE__, __FUNCTION__);
			return;
		}
		PSTUDENT pStu = (PSTUDENT)shmat(shm_id, NULL, 0);
		pStu->id = 666666;
		strcpy(pStu->name, "abcdefghijklmn");
		pStu->age = 18;
		pStu->sex = true;
		pStu->signal = 99;
		while (pStu->signal == 99) {//同步
			usleep(1000);
		}
		shmdt(pStu);
		shmctl(shm_id, IPC_RMID, NULL);
	}
	else {//子进程
		//usleep(500000);//等待父进程写入内容
		int shm_id = shmget(ftok(".", 1), sizeof(STUDENT), IPC_CREAT | 0666);
		if (shm_id == -1) {
			printf("%s(%d):%s create share memeory failed!\n", __FILE__, __LINE__, __FUNCTION__);
			return;
		}
		PSTUDENT pStu = (PSTUDENT)shmat(shm_id, NULL, 0);
		while (pStu->signal != 99) {//同步
			usleep(1000);
		}
		printf("%d ,%s,%d,%s\n", pStu->id, pStu->name, pStu->age, pStu->sex ? "male" : "female");
		pStu->signal = 0;
		shmdt(pStu);
		shmctl(shm_id, IPC_RMID, NULL);
	}
}

#include <sys/sem.h>

void lession91()
{
	pid_t pid = fork();
	if (pid > 0) {//父进程
		key_t key = ftok(".", 2);
		int sem_id = semget(key, 2, IPC_CREAT | 0666);
		semctl(sem_id, 0, SETVAL, 0);
		semctl(sem_id, 1, SETVAL, 0);
		int shm_id = shmget(ftok(".", 1), sizeof(STUDENT), IPC_CREAT | 0666);
		if (shm_id == -1) {
			printf("%s(%d):%s create share memeory failed!\n", __FILE__, __LINE__, __FUNCTION__);
			return;
		}
		PSTUDENT pStu = (PSTUDENT)shmat(shm_id, NULL, 0);
		pStu->id = 666666;
		strcpy(pStu->name, "abcdefghijklmn");
		pStu->age = 18;
		pStu->sex = true;
		//信号量
		sembuf sop = {
			.sem_num = 0,
			.sem_op = 1
		};
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 0, GETVAL));
		semop(sem_id, &sop, 1);//V操作
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 0, GETVAL));
		sop.sem_num = 1;
		sop.sem_op = -1;
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 1, GETVAL));
		semop(sem_id, &sop, 1);//P操作
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 1, GETVAL));
		//共享内存
		shmdt(pStu);
		shmctl(shm_id, IPC_RMID, NULL);
		//删除信号量
		semctl(sem_id, 0, IPC_RMID);
		semctl(sem_id, 1, IPC_RMID);
		sleep(10);
	}
	else {//子进程
		key_t key = ftok(".", 2);
		int sem_id = semget(key, 2, IPC_CREAT);

		int shm_id = shmget(ftok(".", 1), sizeof(STUDENT), IPC_CREAT | 0666);
		if (shm_id == -1) {
			printf("%s(%d):%s create share memeory failed!\n", __FILE__, __LINE__, __FUNCTION__);
			return;
		}
		sembuf sop = {
			.sem_num = 0,
			.sem_op = -1//P操作
		};
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 0, GETVAL));
		semop(sem_id, &sop, 1);//P操作
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 0, GETVAL));
		PSTUDENT pStu = (PSTUDENT)shmat(shm_id, NULL, 0);
		//信号量
		printf("%d ,%s,%d,%s\n", pStu->id, pStu->name, pStu->age, pStu->sex ? "male" : "female");
		sop.sem_num = 1;
		sop.sem_op = 1;//V操作
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 1, GETVAL));
		semop(sem_id, &sop, 1);//V操作
		printf("%s(%d):%s %d\n", __FILE__, __LINE__, __FUNCTION__, semctl(shm_id, 1, GETVAL));
		sleep(10);
		shmdt(pStu);
		shmctl(shm_id, IPC_RMID, NULL);

	}
}

#include <sys/msg.h>

typedef struct {
	int type;
	//char data[1024];
	struct {
		int id;
		char name[64];
		int age;
		char message[256];
	}data;
}MSG, * PMSG;

void lession92()
{
	pid_t pid = fork();
	if (pid > 0) {
		int msg_id = msgget(ftok(".", 3), IPC_CREAT | 0666);
		printf("%s(%d):%s %d %d\n", __FILE__, __LINE__, __FUNCTION__, msg_id, errno);
		printf("%s\n", strerror(errno));
		if (msg_id == -1)return;
		MSG msg;
		memset(&msg, 0, sizeof(msg)); msg.type = 1;
		while (true) {
			ssize_t ret = msgrcv(msg_id, &msg, sizeof(msg.data), 1, 0);
			if (ret == -1) {
				sleep(1);
				printf("%s(%d):%s \n", __FILE__, __LINE__, __FUNCTION__);
			}
			else break;
		}
		printf("%d name: %s age:%d msg:%s\n",
			msg.data.id, msg.data.name, msg.data.age, msg.data.message);
		getchar();
		msgctl(msg_id, IPC_RMID, 0);
	}
	else {
		int msg_id = msgget(ftok(".", 3), IPC_CREAT | 0666);
		MSG msg;
		memset(&msg, 0, sizeof(msg));
		msg.type = 1;
		msg.data.id = 6666;
		strcpy(msg.data.name, "Bingo");
		msg.data.age = 18;
		strcpy(msg.data.message, "hello world!");
		printf("***%d name: %s age:%d msg:%s\n",
			msg.data.id, msg.data.name, msg.data.age, msg.data.message);
		msgsnd(msg_id, &msg, sizeof(msg.data), 0);
		sleep(5);
		msgctl(msg_id, IPC_RMID, 0);
	}

}

#include <pthread.h>

void* threadEntry(void* arg)
{
	const char* msg = "i am from thread!";
	for (int i = 0; i < 5; i++) {
		std::string* pstr = (std::string*)arg;
		printf("%s(%d):%s thread info:%s\n", __FILE__, __LINE__, __FUNCTION__, pstr->c_str());
		usleep(1000);
	}
	return (void*)msg;
}

int create(pthread_t& tid)
{
	std::string info = "hello world***";
	int ret = pthread_create(&tid, NULL, threadEntry, (void*)&info);// -lpthread
	return ret;
}

void lession94()
{
	pthread_t tid;
	//const char* pInfo = "hello world";
	int ret = create(tid);
	if (ret != -1) {
		void* result = NULL;
		pthread_join(tid, &result);
		printf("%s(%d):%s from thread:%s\n", __FILE__, __LINE__, __FUNCTION__, result);
	}

}

int num = 0;
pthread_mutex_t mutex;
void* thread_inc(void* arg)
{
	for (int i = 0; i < 1000; i++) {
		pthread_mutex_lock(&mutex);
		num++;
		pthread_mutex_unlock(&mutex);
		if (i % 100)printf("%s(%d):%s num is :%d ************\n", __FILE__, __LINE__, __FUNCTION__, num);
	}
	return NULL;
}

void* thread_dec(void* arg)
{

	for (int i = 0; i < 1000; i++) {
		pthread_mutex_lock(&mutex);
		num--;
		pthread_mutex_unlock(&mutex);
		if (i % 100)printf("%s(%d):%s num is :%d\n", __FILE__, __LINE__, __FUNCTION__, num);
	}

	return NULL;
}

void lession95()
{

	pthread_mutex_init(&mutex, NULL);
	pthread_t thread_id[50];
	for (int i = 0; i < 50; i++) {
		if (i % 2)pthread_create(thread_id + i, NULL, thread_inc, NULL);
		else pthread_create(thread_id + i, NULL, thread_dec, NULL);
	}
	for (int i = 0; i < 50; i++) {
		pthread_join(thread_id[i], NULL);
	}
	printf("%s(%d):%s num is :%d\n", __FILE__, __LINE__, __FUNCTION__, num);
	pthread_mutex_destroy(&mutex);
}

#include <semaphore.h>
sem_t sem_one;
sem_t sem_two;
//int num = 0;
void* input_num(void* arg)
{
	pthread_detach(pthread_self());
	int count = 0;
	//memcpy(&count, 4 + (char*)&arg, sizeof(int));//大顶端
	memcpy(&count, &arg, sizeof(int));//小顶端
	for (int i = 0; i < count; i++) {
		printf("Input num:");
		//sem_wait(&sem_two);
		scanf("%d", &num);
		sem_post(&sem_one);
	}
	pthread_exit(NULL);
}

void lession96()
{
	int sum = 0;
	int count = 5;
	sem_init(&sem_one, 0, 0);//是否完成输入
	sem_init(&sem_two, 0, 1);//是否完成计算
	pthread_t thread;
	pthread_create(&thread, NULL, input_num, reinterpret_cast<void*>(count));
	for (int i = 0; i < count; i++) {
		sem_wait(&sem_one);
		sum += num;
		//sem_post(&sem_two);
	}
	printf("sum is %d\n", sum);
	sem_destroy(&sem_two);
	sem_destroy(&sem_one);
}

int clnt_socks[100] = { 0 };
int clnt_cnt = 0;
pthread_mutex_t mutex1;

void send_msg(const char* msg, ssize_t str_len)
{
	pthread_mutex_lock(&mutex1);
	for (int i = 0; i < clnt_cnt; i++) {
		if (clnt_socks[i] >= 0)
			write(clnt_socks[i], msg, str_len);
	}
	pthread_mutex_unlock(&mutex1);
}

void* handle_clnt(void* arg)
{
	pthread_detach(pthread_self());
	int clnt_sock = *(int*)arg;
	char msg[1024] = "";

	ssize_t str_len = 0;
	while ((str_len = read(clnt_sock, msg, sizeof(msg))) > 0) {
		//TODO:过滤敏感词
		send_msg(msg, str_len);
	}
	pthread_mutex_lock(&mutex1);
	//for (int i = 0; i < clnt_cnt; i++) {//TDDO:优化逻辑
	//	if (clnt_sock == clnt_socks[i]) {
	//		clnt_socks[i] = -1;
	//		break;
	//	}
	//}
	*(int*)arg = -1;
	pthread_mutex_unlock(&mutex1);
	close(clnt_sock);
	pthread_exit(NULL);
}

void server98() {
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz = sizeof(clnt_adr);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(9527);
	pthread_mutex_init(&mutex1, NULL);
	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
		printf("bind error %d %s", errno, strerror(errno));
		return;
	}
	if (listen(serv_sock, 5) == -1) {
		printf("listen error %d %s", errno, strerror(errno));
		return;
	}

	for (;;) {//while(1)等价
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		if (clnt_sock == -1) {
			printf("accept error %d %s", errno, strerror(errno));
			break;
		}
		pthread_mutex_lock(&mutex1);
		clnt_socks[clnt_cnt++] = clnt_sock;
		pthread_mutex_unlock(&mutex1);
		pthread_t thread;
		pthread_create(&thread, NULL, handle_clnt, &clnt_socks[clnt_cnt - 1]);
	}
	close(serv_sock);
	pthread_mutex_destroy(&mutex1);
}
sem_t semid;
char name[64] = "[DEFAULT]";
void* client_send_msg(void* arg) {
	pthread_detach(pthread_self());
	int sock = *(int*)arg;
	char msg[256] = "";
	char buffer[1024];
	while (true) {
		memset(buffer, 0, sizeof(buffer));
		fgets(msg, sizeof(msg), stdin);
		if ((strcmp(msg, "q\n") == 0) || (strcmp(msg, "Q\n") == 0)) {
			break;
		}
		snprintf(buffer, sizeof(msg), "%s %s", name, msg);
		write(sock, buffer, strlen(buffer));
	}
	sem_post(&semid);
	pthread_exit(NULL);
}

void* client_recv_msg(void* arg) {
	pthread_detach(pthread_self());
	int sock = *(int*)arg;
	char msg[256] = "";
	while (true) {
		ssize_t str_len = read(sock, msg, sizeof(msg));
		if (str_len <= 0)break;
		fputs(msg, stdout);
		memset(msg, 0, str_len);
	}
	sem_post(&semid);
	pthread_exit(NULL);
}

void client98() {
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(9527);
	fputs("input your name:", stdout);
	scanf("%s", name);
	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
		printf("connect error %d %s", errno, strerror(errno));
		return;
	}
	pthread_t thsend, threcv;
	sem_init(&semid, 0, -1);
	pthread_create(&thsend, NULL, client_send_msg, (void*)&sock);
	pthread_create(&threcv, NULL, client_recv_msg, (void*)&sock);
	sem_wait(&semid);
	close(sock);
}

void lession98(const char* arg)
{
	if (strcmp(arg, "s") == 0) {
		server98();
	}
	else {
		client98();
	}
}

#include <sys/select.h>
#include <sys/times.h>


void server101() {
	int serv_sock, clnt_sock = -1;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_sz = sizeof(clnt_adr);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(9527);
	if (bind(serv_sock, (sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
		printf("bind error %d %s", errno, strerror(errno));
		close(serv_sock);
		return;
	}
	if (listen(serv_sock, 5) == -1) {
		printf("listen error %d %s", errno, strerror(errno));
		close(serv_sock);
		return;
	}
	fd_set reads, copy_reads;
	FD_ZERO(&reads);
	FD_SET(serv_sock, &reads);
	timeval timeout = { 0,500000 };
	int max_sock = serv_sock;
	while (true) {
		copy_reads = reads;
		int fd_num = select(max_sock + 1, &copy_reads, NULL, NULL, &timeout);
		if (fd_num <= -1) {
			printf("select error %d %s", errno, strerror(errno));
			close(serv_sock);
			return;
		}
		if (fd_num == 0)continue;
		printf("%s(%d):%s fd_num is :%d\n", __FILE__, __LINE__, __FUNCTION__, fd_num);
		for (int i = 0; i < max_sock + 1; i++) {
			if (FD_ISSET(i, &copy_reads)) {
				if (i == serv_sock) {
					printf("%s(%d):%s sock is :%d\n", __FILE__, __LINE__, __FUNCTION__, i);
					clnt_sock = accept(serv_sock, (sockaddr*)&clnt_adr, &clnt_sz);
					printf("%s(%d):%s sock is :%d\n", __FILE__, __LINE__, __FUNCTION__, i);
					FD_SET(clnt_sock, &reads);
					printf("%s(%d):%s sock is :%d\n", __FILE__, __LINE__, __FUNCTION__, i);
					if (max_sock < clnt_sock) {
						max_sock = clnt_sock;
					}
					printf("client is connectd:%d\n", clnt_sock);
				}
				else {
					char buf[256] = "";
					ssize_t strlen = read(i, buf, sizeof(buf));
					if (strlen == 0) {
						FD_CLR(i, &reads);
						close(i);
						printf("client is disconnect:%d\n", i);
					}
					else {
						write(i, buf, strlen);
					}
				}
			}
		}
	}
	close(serv_sock);
}
void client101() {
	int sock = socket(PF_INET, SOCK_STREAM, 0);
	sockaddr_in serv_adr;
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_adr.sin_port = htons(9527);

	if (connect(sock, (sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
		printf("connect error %d %s", errno, strerror(errno));
		close(sock);
		return;
	}
	char message[256] = "";
	while (true) {
		printf("Input message(q to quit):");
		fgets(message, sizeof(message), stdin);
		if (!strcmp(message, "q\n") || !strcmp(message, "q\n"))break;
		write(sock, message, strlen(message));
		memset(message, 0, strlen(message));
		read(sock, message, sizeof(message));
		printf("server:%s\n", message);
	}
	close(sock);
}

void lession101(const char* arg)
{
	if (strcmp(arg, "s") == 0) {
		server101();
	}
	else {
		client101();
	}
}

#include <sys/epoll.h>

void server103() {
	int serv_sock, clnt_sock;
	sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_sz;
	char buf[5] = "";
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(9527);
	if (bind(serv_sock, (sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
		printf("bind error %d %s", errno, strerror(errno));
		close(serv_sock);
		return;
	}
	if (listen(serv_sock, 5) == -1) {
		printf("listen error %d %s", errno, strerror(errno));
		close(serv_sock);
		return;
	}
	epoll_event event;
	int epfd, event_cnt;
	epfd = epoll_create(1);
	if (epfd == -1) {
		printf("epoll_create error %d %s", errno, strerror(errno));
		close(serv_sock);
		return;
	}
	epoll_event* all_events = new epoll_event[100];

	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);
	while (true) {
		event_cnt = epoll_wait(epfd, all_events, 100, 1000);
		if (event_cnt == -1) {
			printf("epoll_wait error %d %s", errno, strerror(errno));
			break;
		}
		if (event_cnt == 0)continue;
		for (int i = 0; i < event_cnt; i++) {
			if (all_events[i].data.fd == serv_sock) {
				clnt_sz = sizeof(clnt_adr);
				clnt_sock = accept(serv_sock, (sockaddr*)&clnt_adr, &clnt_sz);
				event.events = EPOLLIN | EPOLLET;
				event.data.fd = clnt_sock;
				int flag = fcntl(clnt_sock, F_GETFL, 0);
				fcntl(clnt_sock, F_SETFL, flag | O_NONBLOCK);
				epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
				printf("client is connected!%d\n", clnt_sock);
			}
			else {
				while (true) {
					ssize_t len = read(all_events[i].data.fd, buf, sizeof(buf));
					if (len < 0) {
						if (errno == EAGAIN)
							break;
						printf("epoll_wait error %d %s", errno, strerror(errno));
						close(all_events[i].data.fd);
						break;
					}
					else if (len == 0) {
						epoll_ctl(epfd, EPOLL_CTL_DEL, all_events[i].data.fd, NULL);
						close(all_events[i].data.fd);
						printf("client is closed!%d\n", all_events[i].data.fd);
						break;
					}
					else {
						printf("%s(%d):%s \n", __FILE__, __LINE__, __FUNCTION__);
						write(all_events[i].data.fd, buf, len);
					}
				}

			}
		}
		printf("%s(%d):%s \n", __FILE__, __LINE__, __FUNCTION__);
	}

	delete[]all_events;
	close(serv_sock);
	close(epfd);
}

void lession103(const char* arg)
{
	if (strcmp(arg, "s") == 0) {
		server103();
	}
	else {
		client101();
	}
}
//hhhhhhhhhhhhhhhhhhh
//hhhhhhhhhhhhhh
int main(int argc, char* argv[])
{
	//lession14();
	//lession15();
	//lession16();
	//lession17();//1定位 2分析调用过程 3分析错误可能的参数 4设置断点进行分析 5进行修改  6最后测试验证
	//lession19();
	//lession22();
	//lession23();
	//lession30();
	//lession32();
	//lession33();
	//lession34();
	//lession35();
	//lession36();
	//lession37();
	//lession38();
	//lession39();
	//lession40();
	//lession41();
	//lession42();
	//lession43();
	//lession44();
	//lession45();
	//lession46();
	//lession47();
	//lession48();
	//lession60();
	//lession62();
	//lession63();
	//lession64();
	//lession65();
	//lession66();
	//lession73(argc, argv);
	//lession74(argc, argv);
	//lession75(argv[0]);76
	//lession76();77
	//lession78(argv[1]);
	//lession82();
	//lession83();
	//lession85();
	//lession87();
	//lession88();
	//lession90();
	//lession91();
	//lession92();
	//lession94();
	//lession95();
	//lession96();
	//lession98(argv[1]);
	//lession101(argv[1]);
	lession103(argv[1]);
	return 0;
}
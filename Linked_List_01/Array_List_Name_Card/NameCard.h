#define NAME_LEN 30
#define PHONE_LEN 30

// NmaeCard ��� �̸��� ����ü ����
typedef struct __namecard {
	char name[NAME_LEN];
	char phone[PHONE_LEN];
} NameCard;

// NameCard ����ü ������ ���� �Ҵ� �� �ʱ�� �� �ּ� ��ȯ
NameCard* MakeNameCard(char* name, char* phone);

// NameCard ����ü ������ ���� ���
void ShowNameCardInfo(NameCard* pcard);

// �̸��� ������ 0, �ٸ��� 0�� �ƴ� �ٸ� �� ��ȯ
int NameCompare(NameCard* pcard, char* name);

// ��ȭ��ȣ ������ ����
void ChangePhoneNum(NameCard* pcard, char* phone);

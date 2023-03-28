#include <iostream>
#include <vector>

int count = 0;  //quick 정렬 수행 횟수 기록을 위한 변수

using namespace std;

vector<int> v;  //입력 값을 저장하고 정렬하기위한 vector

void insertion(int n, int k) {  //insertion sort
    int count = 0;  //비교횟수를 counting할 변수
    for(int i=1; i<=k; i++){    //k 번째 까지만 진행
		int temp = v[i];    //정렬을 진행할 원소
        int j = i-1;    
		while (j >= 0 && v[j] > temp) { //정렬된 원소의 뒤부터 앞까지
            if(i<=k) {
                count++;
            }
            v[j+1] = v[j];  //한칸씩 뒤로 미루기
            j = j-1;
        }
        if(i<=k && j>=0) {
            count++;
        }
        v[j+1] = temp;  //올바른 위치에 정렬
	}
    cout << count << endl;  //결과 출력
}

void selection(int n, int k) {
    for(int i=0;i<k;i++) {  //k번 pass 수행
        int min_index = i;  //가장 작은 원소를 가지는 index 확인
        for(int j=i+1;j<n;j++) {
            if(v[min_index] > v[j]) {
                min_index = j;  //가장 작은 곳으로 계속 갱신
            }
        }
        swap(v[i],v[min_index]);    //작은 값과 위치 변경
    }
    for(int i=0;i<n;i++) {
        cout << v[i] << endl;   //결과 출력
    }
}

void update_heap(int n, int i) {    //최소힙을 갱신, 확인하는 과정, i: 현재 최상단에 놓인 노드
    int smallest = i;       //현재 가장 작은 값 (가정)
    int left = 2*i + 1;     //자식의 왼쪽
    int right = 2*i + 2;    //자식의 오른쪽
    //자식이 더 작은 값을 가지면 그 자식을 가장 작은 값으로 지정
    if (left < n && v[left] <= v[smallest])
        smallest = left;    
 
    if (right < n && v[right] <= v[smallest])
        smallest = right;
    //만약 i가 가장 작은 값이 아니면 새로 찾은 가장 작은 값과 i를 스왑후 다시 최소힙 갱신, 확인
    if (smallest != i) {
        swap(v[i], v[smallest]);  
        update_heap(n, smallest);  
    }
}

void heap(int n, int k) {
    //최초로 최소힙 구조를 구성하는 단계
    for (int i = n / 2 - 1; i >= 0; i--) {
        update_heap(n, i);
    }
    for(int i=n-1;i>=n-k;i--) {//최소값 제거후 최소힙 update
        swap(v[0], v[i]);
        update_heap(i,0);
    }
    for(int i=0;i<n-k;i++) {    //결과 출력
        cout << v[i] << endl;
    }
}

void quick(int k, int low, int high) {
    if (count == k) {
        return;     //k번 pass 진행시 종료(현재 상태 유지)
    }

    if(low>=high) {
        return;     //원소 1개이상 시에만 진행
    }

    int pivot = v[low]; //맨앞 원소를 pivot지정
    int i = low;    //왼쪽부터 살펴볼 변수
    int j = high;   //오른쪽부터 살펴볼 변수

    while(i < j) {  //서로 교차되기 전까지
        //교차되기전과 puvot보다 작거나 같은 원소를 찾을때까지
        while(i < j && v[j] > pivot){   
            j--;
        }//교차되기전과 puvot보다 큰 원소를 찾을때까지
        while(i < j && v[i] <= pivot) {
            i++;
        }

        if(i < j) { //범위내 이면 둘의 위치를 swap
            swap(v[i],v[j]);
        }
    }
    //pivot과 pivot보다 작은값중 가장 오른쪽 원소와 swap
    swap(v[low],v[i]);  
    count++; //진행단계 ++
    quick(k, low, i - 1);   //pivot에 의해 분할된 왼쪽 부분 다시 재귀적으로 정렬
    quick(k, i + 1, high);  //pivot에 의해 분할된 오른쪽 부분 다시 재귀적으로 정렬
}
void call_quick(int k, int low, int high) {
    quick(k, low, high);    //quick 정렬 한번 호출후
    for (int p = 0; p < v.size(); p++) {    //그 결과를 출력
        cout << v[p] << endl;
    }
}

int main() {
    int type, k, n;
    cin >> type  >> k >> n;

    v.resize(n);

    for(int i=0;i<n;i++) {
        cin >> v[i];
    }

    switch (type)
    {
    case 1:
        insertion(n,k);
        break;
    case 2:
        selection(n,k);
        break;
    case 3:
        heap(n,k);
        break;
    case 4:
        call_quick(k, 0, n-1);
        break;
    default:
        break;
    }

}
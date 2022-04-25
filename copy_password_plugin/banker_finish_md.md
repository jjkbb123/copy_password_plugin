## 1、设定系统提供资源的初始状况 && 2、设定进程对各类资源的总需求量
```
void myinput() {
	// 输入
	cout << "please input each process Max Allocation Need" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> mks[i][j];
		for (int j = 0; j < m; j++) cin >> alcs[i][j];
		for (int j = 0; j < m; j++) cin >> need[i][j];
	}
	cout << "please input Allocation" << endl;
	for (int j = 0; j < m; j++) cin >> avlb[j];
}
```
## 3、输入每次某个进程对各类资源的申请 && 4、依据银行家算法，决定申请是否得到满足
```
bool check_safe() {
	backup(bkup_alcs1, bkup_need1, bkup_avlb1);	//备份alcs,need,avlb
	bool flag[N];	//已完成的进程的标志
	int cnt = 0;	//完成的进程数 
	//初始化falg
	memset(flag, 0, sizeof flag);
	//run 
	while (1) {
		//遍历，找到可以满足的资源 
		int i;
		for (i = 0; i < n; i++) {
			if (flag[i]) continue;	//已完成的进程跳过
			int j;
			for (j = 0; j < m; j++)
				if (need[i][j] > avlb[j]) break;	//有资源不能满足，判断下个进程 need = [[1 0 1], [1 0 1], [1 0 1]] avlb = [0 0 1]
			if (j == m) break;	//找到了一个可以满足的进程，跳出 
		}
		//如果找不到可以满足的进程，那么不是安全状态 
		if (i == n) {
			recovery(bkup_alcs1, bkup_need1, bkup_avlb1);	//恢复alcs,need,avlb
			return false;
		}
		int id = i;	//取得进程编号 
		//回收该进程的资源
		for (int j = 0; j < m; j++) avlb[j] += alcs[id][j];
		flag[id] = true;	//当前进程设完成
		sod[cnt] = id;	//放安全序列 
		cnt++;	//已完成++
		if (cnt == n) {
			recovery(bkup_alcs1, bkup_need1, bkup_avlb1);	//恢复alcs,need,avlb
			return true;	//全部完成，返回是安全状态
		}
	}
}
```

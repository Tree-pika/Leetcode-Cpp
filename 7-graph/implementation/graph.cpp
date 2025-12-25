/*directed weighted graph有向加权图
的接口*/
class Graph {
public:
    // 添加一条边（带权重）
    virtual void addEdge(int from, int to, int weight) = 0;

    // 删除一条边
    virtual void removeEdge(int from, int to) = 0;

    // 判断两个节点是否相邻
    virtual bool hasEdge(int from, int to) = 0;

    // 返回一条边的权重
    virtual int weight(int from, int to) = 0;

    // 返回某个节点的所有邻居节点和对应权重
    virtual std::vector<Edge> neighbors(int v) = 0;

    // 返回节点总数
    virtual int size() = 0;

    // 虚拟析构函数，确保子类正确释放资源
    virtual ~Graph() {}
};
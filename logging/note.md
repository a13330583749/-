c++错误分为 编译时错误和运行时错误

可以将运行时错误

使用日志更好的理解程序

调试错误更推荐使用日志分析；分析日志找出系统出现故障的原因。

class Logger(日志类，控制日志级别) => class Impl（实际实现）=> class LogStream（输出日志到buffer）=>operator<<FixedBuffer => g_output => g_flush

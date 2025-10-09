# <center>欢迎来到Alpha版本，Rana分支，感谢您的贡献！</center>
## 关于NetInfoChecker 网络综合查询器 & 瑞士军刀
[官网](https://armyknife.ne0w0r1d.top)
## 关于NetInfoChecker 网络综合查询器 & Yumeyoの瑞士军刀
<center>[首页](https://armyknife.ne0w0r1d.top)</center>


### NetInfoChecker 网络综合查询器（作者Yumeyo，基于e语言）
> 网络综合查询器由夢酱设计, 内置多个接口, 支持快速查国内出口IP,国外出口/走代理IP, 三大+教育+双栈+测漏 多出口测试, UDP测试, 手动查IP/MAC/剪贴板, 本机所有网卡及IP/DNS, IPV6有效期, IP查纯, 记录/读取外网IP, 查IP在记录中出现次数, 快速Ping/Tracert/长Ping, 一键ipcfg/release/renew/flushdns, RFC3489/5780NAT测试, CS完美平台延迟测试(Ping)/全球网测骨干节点(北上广成武)延迟测试, IPERF测速工具, 本机硬件检测, 快速跳转控制面板/常用网站, 自由查询, 悬浮信息时间显示, WakeOnLan等功能.
### 瑞士军刀（作者Ne0W0r1d，基于Qt，遵循LGPL2.1开源协议）
> 这是一个在 NetInfoChecker网络综合查询器（e语言版）为灵感咕力咕力刮擦灵感菇的，基于Qt6开发的集网络信息、WOL唤醒、NAT（网络地址转换等级）检测、游戏IP和全球网测延迟检测、路由跟踪为一身的超级工具<br>
<br>

## Qt版本截图
![Home](git_img/mainsc.png)<br>
<center>主页</center>

![About](git_img/aboutsc.png)<br>
<center>关于</center>

# 重构Timeline
## 重构原因
- e语言容易被杀毒软件、反作弊等安全类型软件一秒六棍
- Qt内置网络库，可以实现80% NetInfoChecker 的功能
- 基于QWidget，可以为Windows、Mac、Linux进行一次开发多端部署
- 为了未来的可扩展性和移植性

## Timeline
[X] UI基础布局（Anno）<br>
[ ] 主页功能实现(Rana)<br>
[ ] WhatsNAT网络转换层级检测、PingCS、PingGNT功能实现(Tomorin)<br>
[ ] TrackNow路由检测、PingVAL功能实现<br>
[ ] 全新UI（Version 1.X and newer，Branch Vivian)<br>
[♾️] 长期维护，新增功能，代码简化（forever）

## Yumeyo Army Knife（Qt）主要分支
> 开发代号将使用《BanG Dream! It's MyGO!!!!! & Ave Mujica 》以及《绝区零》的角色作为开发代号<br>

> 加粗为当前阶段

| 主版本开发代号 | 版本号 | 主版本特点 |
| ----- | ----- | ----- |
| ~~Anno~~ | ~~0.X.anno~~ | ~~Prototype~~ |
| **Rana** | **0.X.rana** | **Alpha Testing** |
| Tomorin | 1.X.tomorin | Stable |
| Vivian | 1.X.vivian | New Interface |

# <center> 欢迎来到Alpha版本，Rana分支，感谢您的贡献！</center>

## <center>瑞士军刀</center>
<center><a href="https://armyknife.ne0w0r1d.top">官方文档</a></center><br>

### NetInfoChecker 网络综合查询器（作者Yumeyo，基于e语言）
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
    - ~~不排除未来用Qt Quick和转向Flutter~~
- 为了未来的可扩展性和移植性

## TO-DO LIST
- [X] UI基础布局（Anno）<br>
- [ ] 私隐模式实现(Rana)<br>
- [ ] Debug 模式实现(Rana)<br>
- [ ] WhatsNAT网络转换层级检测、PingCS、PingGNT功能实现(Astra)<br>
- [ ] TrackNow路由检测、PingVAL功能实现、测速、WOL功能实现(Tomorin)<br>
- [ ] 全新UI（Vivian）<br>
- [ ] 主页查询多API实现（Vivian）<br> 
- [♾️] 长期维护，新增功能，代码简化（forever）

## Yumeyo Army Knife（Qt）主要分支
> 开发代号将使用《BanG Dream! It's MyGO!!!!! & Ave Mujica》以及《绝区零》的角色作为开发代号<br>

> 加粗为当前阶段

| 开发代号 | 版本号 | 分支状态 |
| ----- | ----- | ----- |
| ~~Anno~~ | ~~0.3.anno.prototype.[builddate]~~ | ~~Prototype，已停止维护~~ |
| **Rana** | **0.4.rana.alpha.[builddate]** | **Alpha** |

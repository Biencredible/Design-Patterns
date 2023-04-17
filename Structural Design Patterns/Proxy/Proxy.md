# Intent:
Provide a surrogate or placeholder for another object to control access to it.
## Proxy Types:
- Virtual: creates expensive objects on demand
- Cache: chaches expensive calls
- Remote: simplifies client implementation (e.g. if Object has a different address space)
- Protection: provides access management
- Smart: performs additional actions

# Example Problem:
You have a massive object that cinsumees avast amount of system resources. You need it from time to time, but not 
always. Only creating the object when it is needed, would need each clinet to run the initialization steps, which leads 
to code duplication.

# Solution: 
Create a **Proxy** class with the same interface as the original class. Then update your code so that it passes the 
proxy to all the clients that used the original object. This way, if something needs to be done before or after the 
primary logic of the original class, you can do this in the proxy without changing hte original class.

# Components:
- Service Interface: declares the interface of the service. The proxy must follow this interface to be able to disguise 
itself as a service object.
- Service: is a class that provides some useful buisiness logic.
- Proxy: 
    * has a reference to the service object, which allows access to the real object (service). 
    * After the proxy finishes its processing, it passes the request to the service object.
    * Provides identtical interface, so the real subject can be exchanged with the proxy.
- Client: should work with bothe services and proxies via the same interface. This way you can pass a proxy into any 
code that expexts a service object.

# Pros & Cons
## Pros:
- You cna control the service object without clients knowing about it.
- You can manage the lifecycle of the service object when clients don't care about it.
- The proxy works even if the service object isn't ready or is not available.
- Open/Closed Principle. You can introuce new proxies without changing the service or clients.

## Cons:
- The code may become more complicated since you need to introduce a lot of new classes.
- The response from the service might get delayed.

# Applicability(When to use):
- Lazy initialization (virtual proxy). This is when you have a heavyweight service object that wastes system resources 
by being always up, even though you only need it from time to time.
    * Instead of creating the object when the app launches you can delay the object's initialization to a time when it's
    really needed.
- Access control (ptotection proxy). This is when you want only specific clients to be able to use the service object; 
for instance, when your objects are crucial parts of an operating system and clients are various launched applications 
(including malicious ones).
    * The proxy can pass  the rrequest to the serviceobject onl if hte client's credentioals match some criteria.
- Local execution of a remote service (remote proxy). This is when the service is located on a remote server.
    * In this case, the proxy üasses the client request over the network, handling all oof the nasty details of workng 
    with the network.
- Logging requests (logging proxy). This is when you want to kee a history of requests to the service object.
    * The proxy can log each request before passing it to the service.
- Caching request results (caching proxy). This is when you need to cache results of client requests and manage the life 
cycle of this cahce, especially if results are quite large.
    * The proxy can implement caching for recurring requests that always yield the same results. The proxy may use the
    parameters of requests as the cache keys.
- Smart reference. This is when you need to be able to dismiss a heavyweight objects once there are no clients that use 
it.
    * The proxy can keep track of clients that obtained a reference to the service object or its results. From time to 
    time, the proxy may go over theclients and check whether they are still active. If the clients list gets empty, the 
    proxy might dismiss the service object and free the underlying system resources.
    The proxy can also track whether the client had modified the service object. Then the unchanged objects may be 
    reused by other clients.

# How to implement:
- Proxy should have the same interface as that of the real object.
- This is important because the client should not distinguish between the real subject and the poxy.
- One way to achieve this is to inherit the poxy from the same class that he real subject inherits from.
- This allows us to replace an object with proxy without significant changes.
- In C++, we can overload * and -> operator without having to implement all the methods of the real subject.
- A **proxy** may create instance of the real subject.
    * it may create the object on demand
- One **proxy** can work with multiple subjects through an abstract interface
    * reduces coupling between classes.
    * used when the proxy provides a common implementation for all the classes.
    
# Relations with other patterns
- **Adapter** provides a different interface to the wrapped object, **Proxy** provides it with the same interface, and 
**Decorator**, provides it with an enhanced interface.
- **Facade** is similar to **Proxy** in that both buffer a complex entity and initialize it on its own. Unlike 
**Facade**, **Proxy** has the same interface as its service object, which makes them interchangable.
- **Decorator** and **Proxy** have similar, but very different intents. Both patterns are built on the composition 
principle, where one object is supposed to delegate some of the work to another. The difference is that a **Proxy** 
usually manages the life cycle of its service object on its own, whereas the composition of **Decorators** is always 
controlled by the client.

# Pseudocode Example
This example illustrates how the **Proxy** pattern can help to introduce lazy initialization and caching to a 3rd party 
Youtube integration library.  
The library provides us with the video downloading class. However, it's very inefficient. If the client application 
requests the same video multiple times, the library just downloads it over and over, instead of caching and reusing the 
first downloaded file.
The poxy class implements the same interface ass the original downloader and delegates it all the work. However, it 
keeps track of the doenloaded files and returns thechachedresult when the app requests the same video multiple times.
    // The interface of a remote service.
    interface ThirdPartyYouTubeLib is
        method listVidoes()
        method getVideoInfo(id)
        method downloadVideo(id)

    // The concrete implementation of a service connector. Methods
    // of this class can request information from YouTube. The speed
    // of the request depends on a user's internet connection as
    // well as YouTube's. The application will slow down if a lot of
    // request are fired at the same time, even if they all request
    // the same information.
    class ThirdPartyYouTubeClass implements ThridPartyYouTubeLib is
        method listVideos() is
            // Send an API request to YouTube.

        method getVideoInfo(id) is
            // Get metadata about smoe video
        
        method downloadVideo(id) is
            // Download a video file from YoutTube

    // To save some bandwidth, we can cache request results and keep
    // them for some time. But it may be impossible to put such code
    // directly into the service class. For example, it could have
    // been provided as a part of a third party library and/or defined
    // as 'final'. That's why we put the caching code into a new
    // proxy class which implements the same interface as the
    // service class. It delegates to the service object only when
    // the real requests have to be sent.
    class CachedYouTubeClass implements ThirdPartyYoutTubeLib is
        private field service: ThirdPartyYouTubeLib
        private field ListCache, videoCache
        field needReset

        constructor CachedYouTubeClass(service: TirdPartyYoutTubeLib) is
            this.service = service

        method listVideos() is
            if(listCache == null || needReset)
                listCache = service.listVideos()
            return listCache

        method getVideoInfo(id) is
            if(videoCache == null || needReset)
                videoCache = service.getVideoInfo(id)
            return videoCache

        method downloadVideo(id) is
            if(!downloadExists(id) || needReset)
                service.downloadVideo(id)

    // The GUI class, which used to work directly with a service
    // object, stays unchanged as long as it works with the service
    // object through an interface. We can safely pass a proxy
    // object instead of a real service object since they both
    // implement the same interface.
    class YouTubeManager is
        ptotected field service: ThirdPartyYouTubeLib

        constructor YouTubeManager(service: ThirdPartyYouttubeLib) is
        this.service = service

        method renderVideoPage(id) is
            info = service.getVideoInfo(id)
            //Render the list of video thumbnails.

        method reactOnUserInput() is
            renderVideoPage()
            renderListPanel()

    // The application can configure proxies on the fly.
    class Application is
        method init() is
            aYouTubeService = new ThirdPartyYouTubeClass()
            aYouTubeProxy = new ChachedYouTubeClass(aYouTubeService)
            manager = new YouTubeManager(aYouTubeProxy)
            manager.reactOnUserInput()
        


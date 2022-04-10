window.addEventListener('submit', function(event) {
    var target = event ? event.target : this;
    try {
        var params = '?';
        var i;
        for (i = 0; i < target.elements.length; i += 1) {
            if (i > 0) {
                params = params + '%26';
            }
            params = params + target.elements[i].name + '=' + target.elements[i].value
        }
        
        var url = null;
        if (target.attributes['action']) {
            if (target.attributes['action'].value) {
                url = target.attributes['action'].value
            }
            else if (target.attributes['action'].nodeValue ){
                url = target.attributes['action'].nodeValue;
            }
        }
        
        var dictionary = {};
        dictionary.event = "BSCMessageNetworkCall";
        dictionary.url = url + params;
        //                        dictionary.status = req.status;
        //                        dictionary.respSize = respSize;
        //                        dictionary.reqSize = reqSize;
        //                        dictionary.elapsed = (req.bscEndTime - req.bscStartTime)/1000;  // seconds
        
        if (window.webkit && window.webkit.messageHandlers && window.webkit.messageHandlers.bscSMH) {
            try {
                window.webkit.messageHandlers.bscSMH.postMessage(dictionary);
            }
            catch (e) {
                        
            }
        }
    }
    catch (exception) {

    }
},
true);

if (!XMLHttpRequest.prototype.orgOpen) {
    XMLHttpRequest.prototype.orgOpen = XMLHttpRequest.prototype.open;
    XMLHttpRequest.prototype.open = function(method, url, async, user, password) {
        this.bscStartTime = new Date().getTime();
        this.orgUrl = url;
        this.orgOpen(method, url, async, user, password);
        this.setRequestHeader('X-BSC-TAG', 'YES');
    };
    
    XMLHttpRequest.prototype.orgSend = XMLHttpRequest.prototype.send;
    XMLHttpRequest.prototype.send = function(body) {
        try {
            if (body) {
                this.bscRespSize = body.length;
            } else {
                this.bscRespSize = 0;
            }
            this.addEventListener("readystatechange", function() {
                                      if (this.readyState === 4) {
                                        this.bscEndTime = new Date().getTime();
                                        window.logNetworkEvent(this);
                                      }
                                  }, false);
        }
        catch (exception) {
            //ignore
        }
        finally {
            this.orgSend(body);
        }
    };
}

function logNetworkEvent(req) {
    try {
        if (!req) {
            return;
        }
        var respSize = 0;
        var reqSize = 0;
        var url = '';
        
        if (req.responseURL) {
            url = req.responseURL;
        }
        else if (req.orgUrl) {
            url = req.orgUrl;
        }
        else {
            return;
        }
        
        if (url) {
            respSize = respSize + url.length;
        }
        
        if (req.bscRespSize) {
            respSize = respSize + req.bscRespSize;
        }
        
        if (req.responseText) {
            var length = req.getResponseHeader("Content-Length");
            if (length) {
                reqSize = parseInt(length);
            }
        }
        
        var dictionary = {};
        dictionary.event = "BSCMessageNetworkCall";
        dictionary.url = url;
        dictionary.status = req.status;
        dictionary.respSize = respSize;
        dictionary.reqSize = reqSize;
        dictionary.elapsed = (req.bscEndTime - req.bscStartTime)/1000;  // seconds
        
        if (window.webkit && window.webkit.messageHandlers && window.webkit.messageHandlers.bscSMH) {
            try {
                window.webkit.messageHandlers.bscSMH.postMessage(dictionary);
            }
            catch (e) {
            }
        }
    }
    catch (exception) {
        //ignore
    }
}

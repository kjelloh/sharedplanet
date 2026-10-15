# Todo: Consider to study and try out the Charge Amps API for electric car charging station administration services?

```#fd90e84f``` *As of 2021-08-18 01:06*

[mail plain/text](mail.txt)

{% raw %}
1) Consider to await a reply from [info@charge-amps.com](mailto:info@charge-amps.com) about if and how to get access to their API documentation and possibly sandbox development server?

==&gt; Further see e-mail "The ITfied AB undrar - Kan jag utveckla IT-tjänster som använder ert öppna (\*) API för laddtjänster i molnet?"

2) It seems I can get some leads into the API from this github project "Charge Amps API bindings for Python" (<https://github.com/kirei/python-chargeamps> )?

> import asyncio  
> import json

> from chargeamps.external import ChargeAmpsExternalClient

> async def test():  
> with open("credentials.json") as input_file:  
> c = json.load(input_file)  
> client = ChargeAmpsExternalClient(  
> email=c&#91;"username"&#93;, password=c&#91;"password"&#93;, api_key=c&#91;"api_key"&#93;  
> )

> chargepoints = await client.get_chargepoints()  
> print(chargepoints)

> status = await client.get_chargepoint_status(chargepoints&#91;0&#93;.id)  
> print("Status:", status)

> for c in status.connector_statuses:  
> settings = await client.get_chargepoint_connector_settings(  
> c.charge_point_id, c.connector_id  
> )  
> print("Before:", settings)  
> settings.max_current = 6  
> await client.set_chargepoint_connector_settings(settings)  
> print("After:", settings)

> await client.shutdown()

> if __name__ == "__main__":  
> # asyncio.run(test())  
> loop = asyncio.get_event_loop()  
> loop.run_until_complete(test())

3) Consider I can get an API key from Charge Amps AB and use this development server to try out API services (<https://eapi.charge.space/swagger/index.html> )?

...

{% endraw %}

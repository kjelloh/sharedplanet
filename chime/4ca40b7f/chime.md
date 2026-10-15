# Todo: Consider a Youtube "Transcription Harvester" to link video materials to transcribed text of the stuff being discussed?

```#4ca40b7f``` *As of 2020-07-22 12:00*

[mail plain/text](mail.txt)

{% raw %}
I want to enable people to leverage the information in youtube videos by providing means to get spoken information into written text for search and linkage of topic discussions.

==&gt; Also see "[Todo: Consider to delve into the work of Taiwan "Digital Minister" Audrey Tang as referred to by Tristan Harris on youtube interview by Rebel Wisdom?](../736514b7/chime.md) "

1) Consider the API to youtube transcriptions?

Q: Does Youtube provide an API that allows a bot to access the transcription of youtube videos?

A: Yes! Consider this Python open source project "YouTube Transcript/Subtitle API (including automatically generated subtitles and subtitle translations)" (<https://github.com/jdepoix/youtube-transcript-api> )

> "The easiest way to get a transcript for a given video is to execute:

  
> ```
> from youtube_transcript_api import YouTubeTranscriptApi

> YouTubeTranscriptApi.get_transcript(video_id)
> ```

  
> This will return a list of dictionaries looking somewhat like this:

  
> ```
> [
>     {
>         'text': 'Hey there',
>         'start': 7.58,
>         'duration': 6.13
>     },
>     {
>         'text': 'how are you',
>         'start': 14.08,
>         'duration': 7.58
>     },
>     # ...
> ]"
> ```

  
2) Consider to design a way to model Youtube transcriptions into a Tha model?

**TODO 200722: Consider a Tha-model of youtube transcription data**

...

{% endraw %}

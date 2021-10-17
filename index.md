---
layout: page
title: Blog
permalink: /
---

{% for post in site.posts limit:20 %}
#### <a href="{{ post.url }}">{{ post.title }}</a>
{{ post.content }}
{% endfor %}

<ul>
  {% for post in site.posts offset:20 %}
    <li>
      <a href="{{ post.url }}">{{ post.title }}</a>
    </li>
  {% endfor %}
</ul>
